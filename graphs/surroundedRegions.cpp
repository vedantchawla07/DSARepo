#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb emplace_back
void traverse(vector<vector<char>>& board, int i, int j) {
    //traverse the nodes adjacent to it. anyhow.
    board[i][j] = 'Y';
    int adjRow[] = {0, 0, -1 , 1};
    int adjCol[] = { -1, 1, 0, 0};
    for (int k = 0; k < 4; k++) {
        int surrRow = row + adjRow[k];
        int surrCol = col + adjCol[k];
        if (surrRow >= 0 && surrRow < m && surrCol >= 0 && surrCol < n && board[surrRow][surrCol] == 'O') {
            board[surrRow][surrCol] = 'Y';
            traverse(board, surrRow, surrCol);
        }
    }

}

void solve(vector<vector<char>>& board) {
    int m = board.size(); //rows
    int n = board[0].size(); //cols
    /*    for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                traverse(board, i, 0);
            }
            if (board[i][n - 1] == 'O' && n > 0) {
                traverse(board, i, n - 1);
            }
        }
        for (int i = 1; i < n - 1; i++) {
            if (board[0][i] == 'O')
                traverse(board, 0 , i);
            if (board[m - 1][i] == 'O' && m > 0)
                traverse(board, m - 1, i);
        }*/
    for (int i = 0 ; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                if (board[i][j] == 'O')
                    traverse(board, i, j);
            }
        }
    }
    for (int i = 0 ; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            else if (board[i][j] == 'Y')
                board[i][j] = 'O';
        }
    }

}

int main(int argc, char const *argv[])
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;
    while (t-- > 0) {
        int m , n;
        cin >> m >> n;
        vector<vector<char>> board;
        char x;
        for (int i = 0; i < m; i++) {
            vector<char> temp;
            for (int j = 0; j < n; j++) {
                cin >> x;
                temp.push_back(x);
            }
            board.push_back(temp);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        solve(board);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}