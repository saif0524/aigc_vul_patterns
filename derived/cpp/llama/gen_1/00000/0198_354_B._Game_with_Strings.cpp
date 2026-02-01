#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAXN = 25;
int n;
char table[MAXN][MAXN];

int count_a(const string &s) {
    int res = 0;
    for (char c : s) {
        if (c == 'a') {
            res++;
        }
    }
    return res;
}

int count_b(const string &s) {
    int res = 0;
    for (char c : s) {
        if (c == 'b') {
            res++;
        }
    }
    return res;
}

bool check(const string &s) {
    int x = 0, y = 0;
    for (char c : s) {
        bool found = false;
        if (x + 1 < n && table[x + 1][y] == c) {
            x++;
            found = true;
        }
        if (y + 1 < n && table[x][y + 1] == c) {
            y++;
            found = true;
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

string ans = "DRAW";

void dfs(int step, string s) {
    if (step == 2 * n - 1) {
        int cnt_a = count_a(s);
        int cnt_b = count_b(s);
        if (cnt_a > cnt_b) {
            ans = min(ans, "FIRST");
        } else if (cnt_a < cnt_b) {
            ans = min(ans, "SECOND");
        } else {
            ans = min(ans, "DRAW");
        }
        return;
    }
    if (step % 2 == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 && j == 0 && s.empty()) || (i > 0 && s.back() == table[i - 1][j]) || (j > 0 && s.back() == table[i][j - 1])) {
                    string t = s + table[i][j];
                    if (check(t)) {
                        dfs(step + 1, t);
                    }
                }
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 && j == 0 && s.empty()) || (i > 0 && s.back() == table[i - 1][j]) || (j > 0 && s.back() == table[i][j - 1])) {
                    string t = s + table[i][j];
                    if (check(t)) {
                        dfs(step + 1, t);
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> table[i][j];
        }
    }
    dfs(0, "");
    cout << ans << "\n";
    return 0;
}