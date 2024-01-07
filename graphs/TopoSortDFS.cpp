//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
	void dfs(int node, vector<int>& vis, vector<int> adj[], stack<int>& st) {
		for (auto it : adj[node]) {
			if (!vis[it]) {
				vis[it] = 1;
				dfs(it, vis, adj, st);
			}
		}
		st.push(node); //after visiting all the adjacent nodes, I am pushing this node on the stack, thereby insuring that all edges leaving outward from this node are already visited and already in the stack below me.
		//so when I pop them out, they will always occur after this current node, ensuring the topo sort.
	}
public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
		vector<int> vis(V, 0);
		stack<int> st;
		vector<int> ans;
		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				vis[i] = 1;
				dfs(i, vis, adj, st); //calling dfs when the node is not visited. Simple
			}
		}
		//cout << st.size() << endl;
		while (!st.empty()) {
			int node = st.top();
			st.pop();
			ans.push_back(node);
		}
		return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {

	if (V != res.size())
		return 0;

	vector<int> map(V, -1);
	for (int i = 0; i < V; i++) {
		map[res[i]] = i;
	}
	for (int i = 0; i < V; i++) {
		for (int v : adj[i]) {
			if (map[i] > map[v]) return 0;
		}
	}
	return 1;
}

int main() {
	int T;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r" , stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> T;
	while (T--) {
		int N, E;
		cin >> E >> N;
		int u, v;

		vector<int> adj[N];

		for (int i = 0; i < E; i++) {
			cin >> u >> v;
			adj[u].push_back(v);
		}

		Solution obj;
		vector <int> res = obj.topoSort(N, adj);

		cout << check(N, res, adj) << endl;
	}

	return 0;
}
// } Driver Code Ends