#include <bits/stdc++.h>
using namespace std;

void move(vector<string>& board, int n, char d) {
    if (d == 'U') {
        for (int c = 0; c < n; ++c) {
            int write = 0;
            for (int r = 0; r < n; ++r) {
                if (board[r][c] != '.') {
                    board[write++][c] = board[r][c];
                }
            }
            while (write < n) board[write++][c] = '.';
        }
    } else if (d == 'D') {
        for (int c = 0; c < n; ++c) {
            int write = n - 1;
            for (int r = n - 1; r >= 0; --r) {
                if (board[r][c] != '.') {
                    board[write--][c] = board[r][c];
                }
            }
            while (write >= 0) board[write--][c] = '.';
        }
    } else if (d == 'L') {
        for (int r = 0; r < n; ++r) {
            int write = 0;
            for (int c = 0; c < n; ++c) {
                if (board[r][c] != '.') {
                    board[r][write++] = board[r][c];
                }
            }
            while (write < n) board[r][write++] = '.';
        }
    } else if (d == 'R') {
        for (int r = 0; r < n; ++r) {
            int write = n - 1;
            for (int c = n - 1; c >= 0; --c) {
                if (board[r][c] != '.') {
                    board[r][write--] = board[r][c];
                }
            }
            while (write >= 0) board[r][write--] = '.';
        }
    }
}

void execute(vector<string>& board, int n, const string& seq, int start, int end) {
    for (int i = start; i < end; ++i) {
        if (seq[i] == '(') {
            int balance = 1, j = i + 1;
            while (balance != 0) {
                if (seq[j] == '(') ++balance;
                else if (seq[j] == ')') --balance;
                ++j;
            }
            int k = j;
            while (isdigit(seq[k])) ++k;
            long long rep = stoll(seq.substr(j, k - j));
            for (long long r = 0; r < rep; ++r) {
                execute(board, n, seq, i + 1, j - 1);
            }
            i = k - 1;
        } else {
            move(board, n, seq[i]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;
        vector<string> board(n);
        for(int i=0;i<n;i++) cin >> board[i];
        string seq;
        cin >> seq;
        execute(board, n, seq, 0, seq.size());
        for(int i=0;i<n;i++) cout << board[i] <<'\n';
    }
}