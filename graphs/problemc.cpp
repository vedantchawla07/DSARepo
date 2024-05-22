#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<vector<int>>& grid) {
    int ans = 0;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> ini(m, vector<int>(n, 0));
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            int currValue = grid[i][j];
            int currMax = 0;
            for (int k = i + 1; k < m; k++) {
                int surrValue = grid[k][j];
                if (surrValue > ` currValue) {
                    if (surrValue - currValue + ini[i][j] > ini[k][j]) {
                        ini[k][j] =  surrValue - currValue + ini[i][j];
                    }
                }
            }
            for (int k = j + 1; k < n; k++) {
                int surrValue = grid[i][k];
                if (surrValue > currValue) {
                    if (surrValue - currValue + ini[i][j] > ini[i][k]) {
                        ini[i][k] = surrValue - currValue + ini[i][j];
                    }
                }
            }
            ans = max(ans, ini[i][j]);
        }
    }
    return (ans != 0) ? ans : -1;
}

int main() {
    int n, m;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    cout << maxScore(grid);
}