//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

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
// } Driver Code Ends
class Solution {
public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        int count = 0;
        int maxRow = 0, maxCol = 0;
        for (int i = 0; i < n; i++) {
            auto it = stones[i];
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet ds(maxRow + maxCol + 2);
        vector<int> mark(maxRow + maxCol + 2);
        for (int i = 0; i < n; i++) {
            int nodeRow = stones[i][0];
            int nodeCol = stones[i][1] + maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);
            mark[nodeCol] = 1;
            mark[nodeRow] = 1;
        }
        for (int i = 0; i < maxRow + maxCol + 2; i++) {
            if (ds.findUltimateParent(i) == i && ds.size[i] > 1) {
                count++;
            }
        }
        return n - count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends