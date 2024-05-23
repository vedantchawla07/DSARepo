//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
private:
	vector<int> tin, low, mark, vis, ans;
	int totalTime = 0;
	void dfs(int node, int parent, vector<int> adj[]) {
		vis[node] = 1;
		tin[node] = low[node] = totalTime;
		totalTime++;
		int child = 0;
		for (int i = 0; i < adj[node].size(); i++) {
			int surrNode = adj[node][i];
			if (vis[surrNode]) {
				low[node] = min(low[node], tin[surrNode]);
			} else {
				dfs(surrNode, node, adj);
				child++;
				low[node] = min(low[node], low[surrNode]);
				if (low[surrNode] >= tin[node] && parent != -1) {
					mark[node] = true;
				}
			}
			if (parent == -1 && child >= 2) {
				mark[node] = true;
			}
		}
	}
public:
	vector<int> articulationPoints(int V, vector<int>adj[]) {
		tin.resize(V, 0);
		low.resize(V, 0);
		mark.resize(V, 0);
		vis.resize(V, 0);
		for (int i = 0; i < V; i++) {
			if (!vis[i])
				dfs(i, -1, adj);
		}
		for (int i = 0; i < V; i++) {
			if (mark[i]) {
				ans.push_back(i);
			}
		}
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
		vector<int>adj[V];
		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for (auto i : ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends