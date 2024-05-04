//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {

        // all will have T.C of ElogV.
        set<pair<int, int>> s;
        vector<int> dist(n + 1);
        vector<int> ans;
        for (int i = 1; i <= n; i++)
            dist[i] = INT_MAX;
        dist[1] = 0;
        s.insert({0, 1});
        vector<pair<int, int>> adj[n + 1];
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            adj[u].push_back({v, weight});
            adj[v].push_back({u, weight});
        }

        while (!s.empty()) {
            auto it = *(s.begin());
            int node = it.second;
            int weight = it.first;
            s.erase(it);
            ans.push_back(node);
            for (auto i : adj[node]) {
                int edgeWeight = i.second;
                int surrNode = i.first;
                if (weight + edgeWeight < dist[surrNode]) {
                    if (dist[surrNode] != INT_MAX) {
                        s.erase({dist[surrNode], surrNode});
                        auto it = find(ans.begin(), ans.end(), node);
                        if (it != ans.end())
                            ans.erase(it);
                    }
                    dist[surrNode] = weight + edgeWeight;
                    s.insert({dist[surrNode], surrNode});
                }
            }

        }

        if (dist[n] == INT_MAX)
            return { -1};
        ans.insert(ans.begin(), dist[n]);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
        return ans;

    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[ {edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[ {edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[ {res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends