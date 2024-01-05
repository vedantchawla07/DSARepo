//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]) {

		int vis[V] = {0};
		int color[V] = {0};
		for (int i = 0; i < V; i++) {
			if (vis[i] == 0) {
				vis[i] = 1;
				color[i] = 0;
				queue<pair<int, int>> q;
				q.push({i, -1});
				int yourColor;
				while (!q.empty()) {
					int ele = q.front().first;
					int parentColor = q.front().second;

					if (parentColor == -1) {
						yourColor = 0;
					}
					else {
						yourColor = 1 - parentColor;
					}
					color[ele] = yourColor;
					q.pop();
					for (auto it : adj[ele]) {
						if (vis[it] == 0) {
							vis[it] = 1;
							q.push({it, yourColor});
						}
						else {
							if (color[it] != parentColor && parentColor != -1) {
								return false;

							}

						}
					}
				}
			}


		}
		return true;
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
		bool ans = obj.isBipartite(V, adj);
		if (ans)cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends