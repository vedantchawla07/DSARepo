//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private:
	void traversal(vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int, int>>& temp, int row, int col, int startRow, int startCol) {
		int rowAdj[] = { -1, 1, 0, 0};
		int colAdj[] = {0, 0, -1 , 1};
		for (int i = 0; i < 4; i++) {
			int surrRow = row + rowAdj[i];
			int surrCol = col + colAdj[i];
			if (surrRow >= 0 && surrCol >= 0 && surrRow < grid.size() && surrCol < grid[0].size() && grid[surrRow][surrCol] == 1 && vis[surrRow][surrCol] == 0) {
				vis[surrRow][surrCol] = 1;
				temp.push_back({surrRow - startRow, surrCol - startCol});
				traversal(grid, vis, temp, surrRow, surrCol, startRow, startCol);
			}
		}

	}
public:
	int countDistinctIslands(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		set<vector<pair<int, int>>> s;
		vector<pair<int, int>> temp;
		vector<vector<int>> vis(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] && !vis[i][j]) {
					vis[i][j] = 1;
					temp.push_back({0, 0});
					traversal(grid, vis, temp, i, j, i, j);
					s.insert(temp);
					temp.clear();

				}
			}
		}
		return s.size();
	}
};


//{ Driver Code Starts.

int main() {

	int t;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r" , stdin);
	freopen("output.txt", "w", stdout);
#endif
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
		cout << obj.countDistinctIslands(grid) << endl;
	}
}
// } Driver Code Ends