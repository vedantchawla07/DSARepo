//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int>& vis, int totalTime, vector<int>& tin, vector<int>& low, vector<vector<int>>& ans, int parent) {
        vis[node] = 1;
        tin[node] = low[node] = totalTime;
        totalTime++;
        for (int i = 0; i < adj[node].size(); i++) {
            int surrNode = adj[node][i];
            if (surrNode != parent) {
                if (!vis[surrNode]) {
                    dfs(surrNode, adj, vis, totalTime, tin, low, ans, node);
                    low[node] = min(low[node], low[surrNode]);
                    if (low[surrNode] > tin[node]) {
                        vector<int> temp;
                        temp.push_back(node);
                        temp.push_back(surrNode);
                        ans.push_back(temp);
                    }
                } else {
                    low[node] = min(low[node], low[surrNode]);
                }
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);
        vector<int> tin(n, 0);
        vector<int> low(n, 0);
        vector<vector<int>> ans;
        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, adj, vis, 1, tin, low, ans, -1);
        return ans;
    }
};


int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> connections(E);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            connections[i].push_back(u);
            connections[i].push_back(v);
        }

        Solution obj;
        //vector<vector<int>> ans;
        auto ans =  obj.criticalConnections(V, connections);
        for (auto it : ans) {
            cout << it[0] << " " << it[1] << endl;
        }
    }

    return 0;
}
