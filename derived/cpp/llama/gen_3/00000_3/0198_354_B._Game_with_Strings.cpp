#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = 1;

    for (int i = 0; i < 2 * n - 1; ++i) {
        vector<vector<int>> ndp(n, vector<int>(n, 0));
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                if (dp[x][y]) {
                    if (x + 1 < n) {
                        ndp[x + 1][y] |= dp[x][y];
                    }
                    if (y + 1 < n) {
                        ndp[x][y + 1] |= dp[x][y];
                    }
                }
            }
        }
        dp = ndp;
    }

    int a = 0, b = 0;
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            if (dp[x][y]) {
                for (int i = 0; i <= x; ++i) {
                    for (int j = 0; j <= y; ++j) {
                        if (i + j == 2 * n - 1) {
                            if (t[i][j] == 'a') {
                                a++;
                            } else if (t[i][j] == 'b') {
                                b++;
                            }
                        }
                    }
                }
            }
        }
    }

    if (a > b) {
        cout << "FIRST\n";
    } else if (a < b) {
        cout << "SECOND\n";
    } else {
        cout << "DRAW\n";
    }

    return 0;
}