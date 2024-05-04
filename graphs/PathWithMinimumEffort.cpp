//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(rows, vector<int>(columns, INT_MAX));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        int rowAdj[4] = { -1, 1, 0, 0};
        int colAdj[4] = {0, 0, -1, 1};
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int currEffort = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if (r == rows - 1 && c == columns - 1) {
                return currEffort;
            }
            for (int i = 0 ; i < 4; i++) {
                int surrRow = r + rowAdj[i];
                int surrCol = c + colAdj[i];
                if (surrRow >= 0 && surrRow < rows && surrCol >= 0 && surrCol < columns) {
                    int diff = max(abs(heights[r][c] - heights[surrRow][surrCol]), currEffort);
                    if (diff < dist[surrRow][surrCol]) {

                        dist[surrRow][surrCol] = diff;
                        pq.push({diff, {surrRow, surrCol}});
                    }
                }
            }
        }

    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends