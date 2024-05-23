//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    void dfs(int node, vector<vector<int>>& adj, stack<int>& s, vector<int>& visited) {
        visited[node] = 1;
        for (int i = 0; i < adj[node].size(); i++) {
            int surrNode = adj[node][i];
            if (!visited[surrNode]) {
                dfs(surrNode, adj, s, visited);
            }
        }
        s.push(node);
    }
    void dfs2(int node, vector<vector<int>>& adjT, vector<int>& visited) {
        visited[node] = 1;
        for (int i = 0; i < adjT[node].size(); i++) {
            int surrNode = adjT[node][i];
            if (!visited[surrNode]) {
                dfs2(surrNode, adjT, visited);
            }
        }
    }
public:
    //Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int> visited(V, 0);
        stack<int> s;
        vector<vector<int>> adjT(V);
        int ans = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i])
                dfs(i, adj, s, visited);
        }
        for (int i = 0; i < adj.size(); i++) {
            visited[i] = 0;
            for (int j = 0; j < adj[i].size(); j++) {
                int u = i;
                int v = adj[i][j];
                adjT[v].push_back(u);
            }
        }
        while (!s.empty()) {
            int node = s.top();
            s.pop();
            if (!visited[node]) {
                ans++;
                dfs2(node, adjT, visited);
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
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends