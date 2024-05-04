//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        int m = grid[0].size();
        if (source == destination)
            return 0;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[source.first][source.second] = 0;
        int rowAdj[4] = {0, 0 , -1, 1};
        int colAdj[4] = { -1, 1 , 0 , 0};
        q.push({0, source});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int distance = it.first;
            int row = it.second.first;
            int col = it.second.second;
            for (int i = 0; i < 4; i++) {
                int surrRow = row + rowAdj[i];
                int surrCol = col + colAdj[i];
                if (surrRow >= 0  && surrRow < n && surrCol >= 0  && surrCol < m && grid[surrRow][surrCol] == 1 && distance + 1 <  dist[surrRow][surrCol]) {
                    dist[surrRow][surrCol] = distance + 1;
                    q.push({dist[surrRow][surrCol], {surrRow, surrCol}});
                    if (surrRow == destination.first && surrCol == destination.second) {
                        return distance + 1;
                    }
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends