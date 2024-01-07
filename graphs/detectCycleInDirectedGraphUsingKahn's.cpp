//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {

        vector<int> vis(V, 0);
        vector<int> ans;
        queue<int> q;
        bool  flag = false;
        vector<int> indegree(V, 0);
        for (int u = 0; u < V; u++) {
            for (auto v : adj[u]) {
                indegree[v]++;
            }
        }
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                flag = true;
                q.push(i);
            }
        }
        if (flag == false) { //ek ka bhi indegree 0 nai mila
            return true;   //cyclic hai
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        if (ans.size() == V) {
            return false;//ek topo sort mil gayi matlab hi to cycle nai hai.
        }
        else return true;//ek topological sorting nai mili matlab cycle hai.
    }
};

//{ Driver Code Starts.

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends