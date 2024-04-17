//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    bool dfs(int node, vector<int> adj[], vector<int>& vis) {
        for (auto it : adj[node]) {
            if (!vis[it]) { //if the neighbour node is not visited, visit it
                vis[it] = 2; //making it pathVisited
                if (dfs(it, adj, vis))
                    return true;
            }
            else if (vis[it] == 2) { //checking if the neighbour node is pathVisited or not, if yes, cycle.if no, move to the next neighbor.
                return true;
            }
        }
        vis[node] = 1; //making it only visited.
        return false;
    }
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {

        vector<int> ans;
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) { // checking if it is visited.
                vis[i] = 2;//making it path visited and visited at the same time.
                dfs(i, adj, vis);
            }
        }
        for (int i = 0; i < V; i++) {
            if (vis[i] != 2) {
                //after all the traversals are done, only those nodes which are safe will be marked as 2,rest will be marked as 1(only visited) because of backtracking. But backtracking won't work for nodes which are in cycles.
                ans.push_back(i);
            }
        }
        return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends