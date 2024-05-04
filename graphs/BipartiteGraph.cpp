//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// bool isBipartite(int V, vector<int>adj[]) {
// 	//the mistake which I was making was that I was marking it visited when the neighbours were being seen
// 	//but I wasn't assigning them any color. The problem which arises here is that, suppose a node(z) is already visited
// 	// (and is being evaluated by some other node x), I have no means to check whether color has been alloted to them or not, and if it isn't been alloted why is it that it's not alloted?
// 	//should be alloted when I am visiting that node.
// 	//parent color ko le k chalne ki hi zaruart nai hai . Kyu? It is not important that we don't color it with a wrong color. We can color it with a wrong color.
// 	//Wrong color karo. Jab pata chale ki wrong color kardiye ho tab report kardo.
// 	//parentColor ko le k chalne se tum wrong color karne se bach rahe the.
// 	int vis[V] = {0};
// 	int color[V] = {0};
// 	for (int i = 0; i < V; i++) {
// 		if (vis[i] == 0) {
// 			vis[i] = 1;
// 			color[i] = 0;
// 			queue<pair<int, int>> q;
// 			q.push({i, -1});
// 			int yourColor;
// 			while (!q.empty()) {
// 				int ele = q.front().first;
// 				int parentColor = q.front().second;

// 				if (parentColor == -1) {
// 					yourColor = 0;
// 				}
// 				else {
// 					yourColor = 1 - parentColor;
// 				}
// 				color[ele] = yourColor;
// 				q.pop();
// 				for (auto it : adj[ele]) {
// 					if (vis[it] == 0) {
// 						vis[it] = 1;
// 						q.push({it, yourColor});
// 					}
// 					else {
// 						if (color[it] != parentColor && parentColor != -1) {
// 							return false;

// 						}

// 					}
// 				}
// 			}
// 		}


// 	}
// 	return true;
// }

int bfstraversal(int V, vector<int> adj[], int n, vector<int>& color) {
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (auto it : adj[node]) {
			if (color[it] ==  -1) {//not visited
				color[it] = !color[node];
				q.push(it);
			}
			else if (color[it] == color[node]) {//if it is visited, check if it has the same color as yours
				return 0;
			}
		}
	}
	return 1;
}
/*
NOTES: Firstly, you can color a graph using only two colors if and only if the graph is bipartite.

IMP:

If the graph does not contain a cycle, then it is always bipartite.

If the graph contains an even cycle, then it is always bipartite.

If the graph has an odd cycle(odd number of edges), then the graph can never be bipartite.




*/
int dfstraversal(int V, vector<int> adj[], int node, vector<int>& color) {
	for (auto it : adj[node]) {
		if (color[it] == -1) {
			color[it] = !color[node];
			if (!dfstraversal(V, adj, it, color))
				return 0;
		}
		else if (color[it] == color[node])
			return 0;
	}
	return 1;
}
int isBipartite(int V, vector<int> adj[]) {
	vector<int> color(V, -1);
	for (int i = 0; i < V; i++) {
		if (color[i] == -1) {
			color[i] = 0;
			if (!dfstraversal(V, adj, i, color))
				return 0;
		}
	}
	return 1;
}
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
		//Solution obj;
		cout << isBipartite(V, adj);
	}
	return 0;
}
// } Driver Code Ends