//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> ans;
    //vector<int> visited;
    //the main idea is that we go to a node and then go to node connected to it and so on.
    // the main thing to note is that I cannot pass the visited array as a value as it will lead to each function call having its own visited array instead of a global visited array.
    // the disadvantage of this is that when the function returns, the visited array modified by the callee function is not reflected in the caller function.
    // Hence we either send the visited array back to the caller function or make it global or send a reference to the visited array.
    vector<int> dfs(int vertex, vector<int> adj[], vector<int> visited) {
        visited[vertex] = 1;
        ans.push_back(vertex);
        for (int i = 0; i < adj[vertex].size(); i++) {
            int adjNode = adj[vertex][i];
            if (visited[adjNode] == 0) {
                visited = dfs(adjNode, adj, visited);
            }
        }
        return visited;

    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        //visited.resize(V,0);
        vector<int> visited(V, 0);
        visited = dfs(0, adj, visited);
        return ans;
    }
};

//{ Driver Code Starts.
int main(int argc, char const *argv[])
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        //cout << "This is actually executing " << endl;
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