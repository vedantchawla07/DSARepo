//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	void bfs(vector<vector<int>> grid, vector<vector<int>> &ans, vector<vector<int>> &vis, int row, int col, int m, int n) {
		queue<pair<int, int>> q;
		q.push({row, col});
		int delRow = {1, -1, 0, 0};
		int delCol = {0, 0 , -1, 1};
		while (!q.empty()) {
			int currRow = q.front().first;
			int currCol = q.front().second;
			q.pop();
			for (int i = 0 ; i < 4; i++) {
				int neighRow = currRow + delRow[i];
				int neighCol = currCol + delCol[i];
				if (neighRow >= 0 && neighRow < m && neighCol >= 0  && neighCol < n && grid[neighRow][neighCol] == 0 && ans[neighRow][neighCol])
				}

		}
	}
	//Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
		// Code here
		//See you cannot determine what is the distance from your cell to the nearest 1.
		//Best leave it for the ones to decide. Every 1 will try to do a bfs.
		//And fill the distance according to that. IF already filled, will do a comparison and fill it. Keep a track of visited.
		//Why shouldn't I do a dfs? Because dfs me sab agar visited hai bhi to I'm not sure ki best value pe hai ya nai.
		//BFS me agar visited hai matlab ki wo best value pe hai for that one atleast. Koi aur one usko better value bhale dede.
		int m = grid.size();
		int n = grid[0].size();

		vector<vector<int>> ans(m, vector<int>(n, 0));
		vector<vector<int>> vis(m, vector<int>(n, 0));
		for (int i = 0 ; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1) {
					ans[i][j] = 0;
					vis[i][j] = 1;
					bfs(grid, ans, vis, i, j, m, n);
				}
			}
		}
		return ans;

	}
};

//{ Driver Code Starts.
int main(int argc, char const *argv[])
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r" , stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	//cin >> t;
	while (t-- > 0) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for (auto i : ans) {
			for (auto j : i) {
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends