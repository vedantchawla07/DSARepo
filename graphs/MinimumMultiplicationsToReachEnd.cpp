//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int> dist(100000 , INT_MAX);
        dist[start] = 0;
        queue<pair<int, int>> q;
        q.push({0, start});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int value = it.second;
            int steps = it.first;
            if (value == end)
                return steps;
            for (auto iter : arr) {
                int mul = (value * iter) % 100000 ;
                if (steps + 1 < dist[mul]) {
                    dist[mul] = steps + 1;
                    q.push({steps + 1, mul});
                }
            }
        }
        return -1;
    }
    int minimumMultiplications2(vector<int>& arr, int start, int end) {
        //This one uses normal BFS. Honestly, you don't need to do dijkstra , because the steps are increasing in an ascending order and if you are at a position again, you will obviously have done it earlier in lesser number of steps given that you are using BFS.

        int vis[100000] = {0};
        queue<pair<int, int>> q;
        q.push({start, 0});
        vis[start] = 1;
        int n = arr.size();
        int mod = 100000;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int value = it.first;
            int steps = it.second;
            if (value == end) {
                return steps;
            }
            for (int i = 0; i < n; i++) {
                int mul = (value * arr[i]) % mod;
                if (!vis[mul]) {
                    vis[mul] = 1;
                    q.push({mul, steps + 1});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends