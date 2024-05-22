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

    bool valid(int n , int m, int surrRow, int surrCol) {
        return surrCol >= 0 && surrCol < m && surrRow >= 0 && surrRow < n;

    }
public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n * m);
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<int> ans;
        int rowAdj[4] = { -1, 1, 0 , 0};
        int colAdj[4] = {0 , 0, -1, 1};
        int currAns = 0;
        for (int i = 0; i < operators.size(); i++) {
            int currRow = operators[i][0];
            int currCol = operators[i][1];
            if (!visited[currRow][currCol]) {
                visited[currRow][currCol] = 1;
                currAns += 1;
                for (int j = 0; j < 4; j++) {
                    int surrRow = currRow + rowAdj[j];
                    int surrCol = currCol + colAdj[j];
                    if (valid(n, m , surrRow, surrCol) && visited[surrRow][surrCol]) {
                        //check if they belong to the same parent or not;
                        if (ds.findUltimateParent(currRow * m + currCol) != ds.findUltimateParent(surrRow * m + surrCol)) {
                            currAns -= 1;
                            ds.unionByRank(currRow * m + currCol , surrRow * m + surrCol);
                        }
                    }
                }
            }
            ans.push_back(currAns);

        }
        return ans;

    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        vector<vector<int>> a;

        for (int i = 0; i < k; i++) {
            vector<int> temp;
            for (int j = 0; j < 2; j++) {
                int x; cin >> x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.numOfIslands(n, m, a);

        for (auto x : res)cout << x << " ";
        cout << "\n";
    }
}

// } Driver Code Ends