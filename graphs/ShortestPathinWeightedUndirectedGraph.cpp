//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
#if 0
    This method stores the entire path in the queue ds. Path of paths. You could use a pq as well. Same implementation.

    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        queue<vector<pair<int, int>>> q;
        vector<pair<int, int>> adj[n + 1];
        vector<int> dist(n + 1, INT_MAX);
        dist[1] = 0;
        vector<int> ans;
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            adj[u].push_back({v, weight});
            adj[v].push_back({u, weight});
        }
        q.push({{0, 1}});
        while (!q.empty()) {

            vector<pair<int, int>> temp;
            temp = q.front();
            q.pop();
            int l = temp.size();
            int node = temp[l - 1].second;
            int weight = temp[l - 1].first;
            if (node == n) {
                ans.clear();
                for (auto it : temp) {
                    ans.push_back(it.second);
                }
            }
            for (auto it : adj[node]) {
                int surrNode = it.first;
                int edgeWeight = it.second;
                if (weight + edgeWeight < dist[surrNode]) {
                    dist[surrNode] = weight + edgeWeight;
                    vector<pair<int, int>> temp2 = temp;
                    temp2.push_back({dist[surrNode], surrNode});
                    //temp.insert(temp.begin(), {dist[surrNode], surrNode});
                    q.push(temp2);
                }
            }
        }
        if (ans.size() == 0) {
            return { -1};
        }
        //reverse(ans.begin(), ans.end());
        ans.insert(ans.begin(), dist[n]);
        return ans;

    }
#endif
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        //This method uses the parent technique. You store the parent where you came from in an array and then track back.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, INT_MAX), parent(n + 1, INT_MAX);
        vector<pair<int, int>> adj[n + 1];
        vector<int> ans;
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            adj[u].push_back({v, weight});
            adj[v].push_back({u, weight});
        }
        for (int i = 1; i <= n; i++)
            parent[i] = i;

        pq.push({0, 1});
        parent[1] = 1;
        dist[1] = 0;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int weight = it.first;
            for (auto i : adj[node]) {
                int adjNode = i.first;
                int edgeWeight = i.second;
                if (weight + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = weight + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        if (dist[n] == INT_MAX)
            return { -1};
        int node = n;
        while (parent[node] != node) {
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        ans.push_back(dist[n]);
        reverse(ans.begin(), ans.end());
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