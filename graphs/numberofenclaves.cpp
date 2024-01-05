//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    int dfs(int currRow , int currCol , int n, int m, int numberOfBoundaryLandCells, vector<vector<int>> &grid, vector<vector<int>> &vis) {
        int delRow[] = { -1, +1 , 0 , 0 };
        int delCol[] = {0, 0 , -1, +1};

        for (int i = 0; i < 4; i++) {
            int surrRow = currRow + delRow[i];
            int surrCol = currCol + delCol[i];
            if (surrRow >= 0 && surrRow < n && surrCol >= 0 && surrCol < m && grid[surrRow][surrCol] == 1 && vis[surrRow][surrCol] == 0) {
                vis[surrRow][surrCol] = 1;
                numberOfBoundaryLandCells++;
                numberOfBoundaryLandCells = dfs(surrRow, surrCol, n, m , numberOfBoundaryLandCells, grid, vis);

            }
        }
        return numberOfBoundaryLandCells;

    }
public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int numberOfLandCells = 0;
        int numberOfBoundaryLandCells = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    numberOfLandCells++;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && grid[i][j] == 1 && vis[i][j] == 0) {
                    numberOfBoundaryLandCells++;
                    vis[i][j] = 1;
                    numberOfBoundaryLandCells = dfs(i , j , n , m , numberOfBoundaryLandCells, grid, vis);
                }
            }
        }
        return numberOfLandCells - numberOfBoundaryLandCells ;
    }
};


//{ Driver Code Starts.

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
#endif
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
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends