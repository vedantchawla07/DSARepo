//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
	void bfs(vector<vector<int>> adj, vector<int> &vis, int V, int node) {

		queue<int> q;
		q.push(node);
		while (!q.empty()) {
			int currNode = q.front();
			q.pop();
			for (int i = 0; i < V; i++) {
				if (adj[currNode][i] == 1 && !vis[i]) {
					vis[i] = 1;
					q.push(i);
				}
			}
		}
	}
	int numProvinces(vector<vector<int>> adj, int V) {
		int numOfProvinces = 0;
		vector<int> vis(V, 0);
		for (int i = 0; i < V; i++) {

			if (!vis[i]) {
				vis[i] = 1;
				numOfProvinces++;
				bfs(adj, vis, V, i);
			}
		}

		return numOfProvinces;

	}
};

//{ Driver Code Starts.

int main() {
	int t;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r" , stdin);
	freopen("output.txt", "w", stdout);
#endif

//	cin >> t;
	t = 1;
	while (t--) {
		int V, x;
		cin >> V;

		vector<vector<int>> adj;

		for (int i = 0; i < V; i++)
		{
			vector<int> temp;
			for (int j = 0; j < V; j++)
			{
				cin >> x;
				temp.push_back(x);
			}
			adj.push_back(temp);
		}

		Solution ob;
		cout << ob.numProvinces(adj, V) << endl;
	}
	return 0;
}
// } Driver Code Ends