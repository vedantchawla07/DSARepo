//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	// Function to find the number of islands.
	int numIslands(vector<vector<char>>& grid) {
		// Code here
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
		vector<vector<char>> grid(n, vector<char>(m, '#'));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans << '\n';
	}
	return 0;
}
// } Driver Code Ends