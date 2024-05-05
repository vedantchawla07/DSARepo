//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<pair<ll, ll>> dist(n, {LONG_MAX, 0});
        dist[0] = {0, 1};
        int mod = 1e9 + 7.;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>> , greater<pair<ll, ll>>> pq;
        vector<vector<pair<ll, ll>>> adj(n);
        for (int i = 0; i < roads.size(); i++) {
            ll u = roads[i][0];
            ll v = roads[i][1];
            ll weight = roads[i][2];
            adj[u].push_back({v, weight});
            adj[v].push_back({u, weight});
        }
        pq.push({0, 0});
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            ll node = it.second;
            ll value = it.first;
            for (auto iter : adj[node]) {
                ll adjNode = iter.first;
                ll edgeWeight = iter.second;
                if (value + edgeWeight < dist[adjNode].first) {
                    dist[adjNode] = {value + edgeWeight, dist[node].second};
                    pq.push({dist[adjNode].first, adjNode});
                } else if (value + edgeWeight == dist[adjNode].first) {
                    dist[adjNode].second = (dist[adjNode].second + dist[node].second) % mod;
                }
            }
        }

        return dist[n - 1].second;

    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends