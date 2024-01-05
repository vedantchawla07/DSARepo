//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	void dfs(vector<vector<int>>& image, int cr, int cc, int newColor, int totalRows, int totalCols, int oldColor) {
		if (cr >= 0 && cr < totalRows && cc >= 0 && cc < totalCols && image[cr][cc] == oldColor ) {
			image[cr][cc] = newColor;
			cout << "The current row and columns are " << cr << cc << endl;
			dfs(image, cr, cc + 1, newColor, totalRows, totalCols, oldColor);
			dfs(image, cr, cc - 1, newColor, totalRows, totalCols, oldColor);
			dfs(image, cr + 1, cc, newColor, totalRows, totalCols, oldColor);
			dfs(image, cr - 1, cc, newColor, totalRows, totalCols, oldColor);
		}
	}
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

		int totalRows = image.size();
		int totalCols = image[0].size();
		int oldColor = image[sr][sc];
		cout << "Calling dfs here " << endl;
		if (oldColor != newColor)
			dfs(image, sr , sc , newColor, totalRows, totalCols, oldColor);
		return image;
	}
};

//{ Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for (auto i : ans) {
			for (auto j : i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}


