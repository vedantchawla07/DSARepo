//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> ans;
    //vector<int> visited;
    void dfs(int vertex, vector<int> adj[], vector<int> visited) {
        visited[vertex] = 1;
        ans.push_back(vertex);
        for (int i = 0; i < ans.size(); ++i)
        {
            cout << ans[i] << endl;
        }
        for (int i = 0; i < adj[vertex].size(); i++) {
            int adjNode = adj[vertex][i];
            if (visited[adjNode] == 0) {
                dfs(adjNode, adj, visited);
            }
        }

    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        //visited.resize(V,0);
        vector<int> visited(V);
        dfs(0, adj, visited);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends