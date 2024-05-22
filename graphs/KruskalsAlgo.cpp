//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
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
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTreeUsingPriorityQueue(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for (int i = 0 ; i < V; i++) {
            auto it = adj[i];
            for (auto it1 : it) {
                int v = it1[0];
                int w = it1[1];
                pq.push({w, {i, v}});
            }
        }
        int ans = 0;
        DisjointSet ds(7);
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int w = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if (ds.findUltimateParent(u) != ds.findUltimateParent(v)) {
                ds.unionByRank(u, v);
                ans += w;
            }
        }
        return ans;
    }
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<pair<int, pair<int, int>>> edges;
        int ans = 0;
        for (int i = 0; i < V; i++) {
            int u = i;
            auto it = adj[i];
            for (auto adjNode : it) {
                int v = adjNode[0];
                int w = adjNode[1];
                edges.push_back({w, {u, v}});
            }
        }
        sort(edges.begin(), edges.end());
        DisjointSet ds(V);
        for (int i = 0; i < edges.size(); i++) {
            int w = edges[i].first;
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            if (ds.findUltimateParent(u) != ds.findUltimateParent(v)) {
                ds.unionBySize(u, v);
                ans += w;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }
#if 0
    Solution sol;
    Solution:: DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(3, 4);
    ds.unionByRank(5, 7);
    if (ds.findUltimateParent(3) == ds.findUltimateParent(7)) {
        cout << ds.findUltimateParent(3) << " " << ds.findUltimateParent(7) << endl;
        cout << "Same" << endl;
    }

    else {
        cout << ds.findUltimateParent(3) << " " << ds.findUltimateParent(7) << endl;
        cout << "Not Same" << endl;
    }

    ds.unionByRank(4, 7);
    if (ds.findUltimateParent(3) == ds.findUltimateParent(7)) {
        cout << ds.findUltimateParent(3) << " " << ds.findUltimateParent(7) << endl;
        cout << "Same" << endl;

    }
    else {
        cout << ds.findUltimateParent(3) << " " << ds.findUltimateParent(7) << endl;
        cout << "Not same" << endl;
    }

    ds.print(7);
    return 0;

#endif
}


// } Driver Code Ends