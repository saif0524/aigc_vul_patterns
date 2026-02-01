#include <bits/stdc++.h>
using namespace std;

bool checkWin(vector<string>& board, char player) {
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            if(board[i][j] != '.') continue;
            board[i][j] = player;
            for(int x = 0; x < 4; ++x) {
                if(board[x][0] == player && board[x][1] == player && board[x][2] == player) {
                    board[i][j] = '.';
                    return true;
                }
                if(board[0][x] == player && board[1][x] == player && board[2][x] == player) {
                    board[i][j] = '.';
                    return true;
                }
            }
            if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
                board[i][j] = '.';
                return true;
            }
            if(board[0][3] == player && board[1][2] == player && board[2][1] == player) {
                board[i][j] = '.';
                return true;
            }
            board[i][j] = '.';
        }
    }
    return false;
}

int main(){
    vector<string> board(4);
    for(auto &row : board) cin >> row;
    if(checkWin(board, 'x')) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}