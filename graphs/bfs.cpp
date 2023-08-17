//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	vector<int> ans;
	vector<int> bfsOfGraph(int V, vector<int> adj[]) {
		queue<int> q;
		q.push(0);
		std::vector<int> visited(V, 0);
		ans.push_back(0);
		visited[0] = 1;
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (auto it : adj[v])
			{
				if (visited[it] == 0) {
					q.push(it);
					visited[it] = 1;
					ans.push_back(it);
				}

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
	int tc = 1;
	//cin >> tc;
	while (tc--) {
		int V, E;
		cin >> V >>

		    E;

		vector<int> adj[V];

		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			// 		adj[v].push_back(u);
		}
		// string s1;
		// cin>>s1;
		Solution obj;
		vector<int> ans = obj.bfsOfGraph(V, adj);
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
// } Driver Code Ends