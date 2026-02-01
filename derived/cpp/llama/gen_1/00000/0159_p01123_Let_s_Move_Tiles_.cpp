#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

const int MAXN = 55;
const int MAXLEN = 1005;

char board[MAXN][MAXN];
string seq;

void up() {
    vector<vector<char>> temp(MAXN, vector<char>(MAXN, '.'));
    for (int i = 0; i < MAXN; i++) {
        int index = 0;
        for (int j = 0; j < MAXN; j++) {
            if (board[j][i] != '.') {
                temp[index][i] = board[j][i];
                index++;
            }
        }
    }
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            board[i][j] = temp[i][j];
        }
    }
}

void down() {
    vector<vector<char>> temp(MAXN, vector<char>(MAXN, '.'));
    for (int i = 0; i < MAXN; i++) {
        int index = MAXN - 1;
        for (int j = MAXN - 1; j >= 0; j--) {
            if (board[j][i] != '.') {
                temp[index][i] = board[j][i];
                index--;
            }
        }
    }
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            board[i][j] = temp[i][j];
        }
    }
}

void left() {
    vector<vector<char>> temp(MAXN, vector<char>(MAXN, '.'));
    for (int i = 0; i < MAXN; i++) {
        int index = 0;
        for (int j = 0; j < MAXN; j++) {
            if (board[i][j] != '.') {
                temp[i][index] = board[i][j];
                index++;
            }
        }
    }
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            board[i][j] = temp[i][j];
        }
    }
}

void right() {
    vector<vector<char>> temp(MAXN, vector<char>(MAXN, '.'));
    for (int i = 0; i < MAXN; i++) {
        int index = MAXN - 1;
        for (int j = MAXN - 1; j >= 0; j--) {
            if (board[i][j] != '.') {
                temp[i][index] = board[i][j];
                index--;
            }
        }
    }
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            board[i][j] = temp[i][j];
        }
    }
}

void solve(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    cin >> seq;

    stack<long long> rep;
    for (int i = 0; i < seq.length(); i++) {
        if (seq[i] == '(') {
            string tmp = "";
            i++;
            while (seq[i] != ')') {
                tmp += seq[i];
                i++;
            }
            i++;
            long long cnt = 0;
            while (i < seq.length() && seq[i] >= '0' && seq[i] <= '9') {
                cnt = cnt * 10 + seq[i] - '0';
                i++;
            }
            i--;
            string sub = tmp;
            while (rep.size() > 0) {
                sub += rep.top();
                rep.pop();
            }
            for (int j = 0; j < cnt; j++) {
                rep.push(sub);
            }
        } else if (seq[i] == 'U') {
            up();
        } else if (seq[i] == 'D') {
            down();
        } else if (seq[i] == 'L') {
            left();
        } else if (seq[i] == 'R') {
            right();
        } else {
            while (rep.size() > 0) {
                string sub = rep.top();
                rep.pop();
                for (int j = 0; j < sub.length(); j++) {
                    if (sub[j] == 'U') up();
                    else if (sub[j] == 'D') down();
                    else if (sub[j] == 'L') left();
                    else if (sub[j] == 'R') right();
                }
            }
        }
    }

    while (rep.size() > 0) {
        string sub = rep.top();
        rep.pop();
        for (int j = 0; j < sub.length(); j++) {
            if (sub[j] == 'U') up();
            else if (sub[j] == 'D') down();
            else if (sub[j] == 'L') left();
            else if (sub[j] == 'R') right();
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        if (n == 0) break;
        solve(n);
    }

    return 0;
}