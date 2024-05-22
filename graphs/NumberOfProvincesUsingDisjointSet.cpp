//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    class DisjointSet {
    public:
        vector<int> parent, rank, size;

        DisjointSet(int n) {
            parent.resize(n + 1);
            rank.resize(n + 1, 0);
            size.resize(n + 1, 1);
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        int findUltimateParent(int u) {

            if (u == parent[u]) {
                return u;
            }
            return parent[u] = findUltimateParent(parent[u]);
        }
        void unionByRank(int u , int v) {
            int ulp_u = findUltimateParent(u);
            int ulp_v = findUltimateParent(v);
            //cout << u << " " << ulp_u << " " << rank[ulp_u] << endl;
            //cout << v << " " << ulp_v << " " << rank[ulp_v] << endl;
            if (ulp_u == ulp_v) return;
            if (rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
            }
            else if (rank[ulp_v] < rank[ulp_u]) {
                parent[ulp_v] = ulp_u;
            }
            else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u] = rank[ulp_u] + 1;
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
            cout << "Printing the parent" << endl;
            for (int i = 0; i <= n; i++) {
                cout << parent[i] << " ";
            }
            cout << endl;
            cout << "Printing the rank" << endl;
            for (int i = 0; i <= n; ++i)
            {
                cout << rank[i] << " ";
            }
            cout << endl;
            cout << "Printing the size" << endl;
            for (int i = 0; i <= n; ++i)
            {
                cout << size[i] << " ";
            }
            cout << endl;
        }
    };
    int numProvinces1(vector<vector<int>> adj, int V) {
        DisjointSet ds(V);
        int ans = V;
        vector<pair<int, int>> edges;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (i != j && adj[i][j] == 1) {
                    if (ds.findUltimateParent(i) != ds.findUltimateParent(j)) {
                        ds.unionByRank(i, j);
                        ans--;
                    }
                }
            }
        }
        return ans;
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        DisjointSet ds(V);
        int ans = 0;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adj[i][j] == 1)
                    ds.unionByRank(i, j);
            }
        }
        for (int i = 0; i < V; i++) {
            if (ds.findUltimateParent(i) == i) {
                ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, x;
        cin >> V;

        vector<vector<int>> adj;

        for (int i = 0; i < V; i++)
        {
            vector<int> temp;
            for (int j = 0; j < V; j++)
            {
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }


        Solution ob;
        cout << ob.numProvinces(adj, V) << endl;
    }
    return 0;
}
// } Driver Code Ends