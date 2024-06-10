#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> rows[9];
        unordered_set<int> cols[9];
        unordered_set<int> squares[9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                char value = board[i][j];
                int squareIndex = (i / 3 + j / 3);
                if (rows[i].find(value) != rows[i].end() || cols[j].find(value) != cols[j].end() || squares[i / 3 + j / 3].find(value) != squares[i / 3 + j / 3].end()) {
                    cout << i << ' ' << j << ' ' << i / 3 + j / 3 << ' ' << board[i][j] <<   endl;
                    return false;
                }

                rows[i].insert(value);
                cols[j].insert(value);
                squares[i / 3 + j / 3].insert(value);
            }
        }
        return true;
    }
};

int main()
{
    Solution obj;
    vector<vector<char>> board(9, vector<char>(9, '.'));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }
    cout << obj.isValidSudoku(board) << endl;
    return 0;
}