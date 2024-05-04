//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        vector<int> price(n, INT_MAX);
        price[src] = 0;
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < flights.size(); i++) {
            int src = flights[i][0];
            int dest = flights[i][1];
            int price = flights[i][2];
            adj[src].push_back({dest, price});
        }
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({ -1, {0, src}});
        queue<pair<int, pair<int, int>>> q;
        q.push({ -1, {0, src}});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int currPrice = it.second.first;
            int currCity = it.second.second;
            int stops = it.first;
            if (stops >= K) {
                continue;
            }
            for (auto i : adj[currCity]) {
                if (currPrice + i.second < price[i.first]) {
                    int totalPrice = currPrice + i.second;
                    price[i.first] = totalPrice;
                    q.push({stops + 1, {totalPrice, i.first}});
                }
            }
        }
        if (price[dst] == INT_MAX) {
            return -1;
        }
        return price[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin >> n;
        int edge; cin >> edge;
        vector<vector<int>> flights;

        for (int i = 0; i < edge; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x; cin >> x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }

        int src, dst, k;
        cin >> src >> dst >> k;
        Solution obj;
        cout << obj.CheapestFLight(n, flights, src, dst, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends