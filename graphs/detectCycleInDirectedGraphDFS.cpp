#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb emplace_back

bool traversal(vector<int> adj[], vector<int>& vis, vector<int>& path, int node) {
	path.push_back(node);
	for (int i = 0; i < adj[node].size(); i++) {
		int surrNode = adj[node][i];
		if (!vis[surrNode]) {
			vis[surrNode] = 1;
			if (traversal(adj, vis, path, surrNode))
				return true;
		}
		else {
			//check ye mere path me hai ya nai
			for (int i = 0; i < path.size(); i++) {
				if (path[i] == surrNode) {
					return true;
				}
			}
		}
	}
	path.pop_back();
	return false;
}
bool isCyclic(int V, vector<int> adj[]) {

	vector<int> vis(V, 0);
	vector<int> path;
	for (int i = 0; i < V; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			if (traversal(adj, vis, path, i))
				return true;
		}
	}
	return false;
}
int main(int argc, char const *argv[])
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r" , stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	//cin >> t;
	while (t-- > 0) {
		int V, E;
		cin >> V >> E;
		vector<int> adj[V];
		vector<int> temp;
		int u , v;
		for (int i = 0; i < E; i++) {
			cin >> u >> v;
			adj[u].push_back(v);

		}
		cout << isCyclic(V, adj) << endl;
	}
	return 0;
}