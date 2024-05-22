//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet {

public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n ; i++) {
            parent[i] = i;
        }
    }
    int findUltimateParent(int u) {

        if (parent[u] == u) {
            return u;
        }
        return parent[u] = findUltimateParent(parent[u]);
    }
    void unionByRank(int u, int v) {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u , int v) {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    void print(int n) {
        cout << "Printing rank" << endl;
        for (int i = 1; i <= n; i++) {
            cout << rank[i] << " ";
        }
        cout << endl;
        cout << "Printing parent" << endl;
        for (int i = 1; i <= n; ++i)
        {
            cout << parent[i] << " ";
        }
        cout << endl;
    }

};
class Solution {
private:
    bool isValid(int surrRow, int surrCol, int n) {
        return surrRow >= 0 && surrRow < n && surrCol >= 0 && surrCol < n;
    }
public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        int rowAdj[4] = { -1, 1 , 0 , 0};
        int colAdj[4] = {0, 0, 1, -1};
        int ans = 0;
        DisjointSet ds(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int node = i * n + j;
                    for (int k = 0; k < 4; k++) {
                        int surrRow = i + rowAdj[k];
                        int surrCol = j + colAdj[k];
                        if (isValid(surrRow, surrCol, n) && grid[surrRow][surrCol] == 1) {
                            int surrNode = surrRow * n + surrCol;
                            ds.unionBySize(node, surrNode);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    set<int> s;
                    int currValue = 0;
                    int node = i * n + j;
                    for (int k = 0; k < 4; k++) {
                        int surrRow = i + rowAdj[k];
                        int surrCol = j + colAdj[k];
                        if (isValid(surrRow, surrCol, n) && grid[surrRow][surrCol] == 1) {
                            int surrNode = surrRow * n + surrCol;
                            int ulp = ds.findUltimateParent(surrNode);
                            if (s.find(ulp) == s.end()) {
                                int sizeOfSurrNode = ds.size[ulp];
                                currValue += sizeOfSurrNode;
                                s.insert(ulp);
                            }

                        }
                    }
                    ans = max(ans, currValue + 1);
                }
            }
        }
#if 0
        bool isZero = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    isZero = true;
            }
        }
        if (!isZero) return n * n;
#endif
        for (int i = 0; i < n * n; i++) {
            ans = max(ans, ds.size[ds.findUltimateParent(i)]);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends