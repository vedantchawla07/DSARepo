//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
private:
    void topoSort(int node, vector<pair<int, int>> adj[], stack<int>& st, vector<int>& vis) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (vis[it.first] == 0) {
                topoSort(it.first, adj, st, vis);
            }
        }
        st.push(node);
    }
public:
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        queue<pair<int, int>> q;
        vector<int> weight(N , 0);
        vector<vector<int>> adjMatrix(N, vector<int>(N, 0));
        for (int i = 0; i < M; i++) {
            int node = edges[i][0];
            int surrNode = edges[i][1];
            int weig = edges[i][2];
            adjMatrix[node][surrNode] = weig;
        }
        q.push({0, 0});
        while (!q.empty()) {
            int node = q.front().first;
            int nodeWeight = q.front().second;
            q.pop();
            for (int i = 0; i < N; i++) {
                if (adjMatrix[node][i] != 0) {
                    int surrWeight = nodeWeight + adjMatrix[node][i];
                    if (surrWeight < weight[i] ||  weight[i] == 0) {
                        q.push({i, surrWeight});
                        weight[i] = surrWeight;
                    }
                }
            }
        }
        for (int i = 1; i < N; i++) {
            if (weight[i] == 0) {
                weight[i] = -1;
            }
        }
        return weight;
    }


    vector<int> shortestPathUsingTopoSort(int N, int M, vector<vector<int>>& edges) {
        //convert this to adj list, then find topo sort. store it in a stack/vector. traverse the vertices surrounding it. and then relax the edges whenever needed.
        vector<pair<int, int>> adj[N];
        stack<int> st;
        vector<int> dist(N);
        vector<int> vis(N, 0);
        for (int i = 1; i < N; i++) {
            dist[i] = INT_MAX;
        }

        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        for (int i = 0; i < N; i++) {
            cout << i << " ";
            for (auto it : adj[i]) {
                cout << it.first << "," << it.second << " ";
            }
            cout << endl;
        }

        topoSort(0, adj, st, vis);


        while (!st.empty()) {
            int node = st.top();
            st.pop();
            int wt = dist[node];
            for (auto it : adj[node]) {
                if (wt + it.second < dist[it.first]) {
                    dist[it.first] = wt + it.second;
                }
            }
        }

        for (int i = 1 ; i < N; i++) {
            if (dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }
        return dist;

    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x; cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPathUsingTopoSort(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends