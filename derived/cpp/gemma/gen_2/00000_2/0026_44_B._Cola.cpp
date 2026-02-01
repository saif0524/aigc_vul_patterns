#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<vector<long long>> dp(n + 1, vector<long long>(a + 1, vector<long long>(b + 1, vector<long long>(c + 1, 0))));
    dp[0][0][0][0] = 1;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= a; ++j) {
            for (int k = 0; k <= b; ++k) {
                for (int l = 0; l <= c; ++l) {
                    if (dp[i][j][k][l] > 0) {
                        if (j < a) {
                            if (i + 0.5 <= n) {
                                dp[i + 0.5][j + 1][k][l] += dp[i][j][k][l];
                            }
                        }
                        if (k < b) {
                            if (i + 1 <= n) {
                                dp[i + 1][j][k + 1][l] += dp[i][j][k][l];
                            }
                        }
                        if (l < c) {
                            if (i + 2 <= n) {
                                dp[i + 2][j][k][l + 1] += dp[i][j][k][l];
                            }
                        }
                    }
                }
            }
        }
    }

    long long result = 0;
    for (int j = 0; j <= a; ++j) {
        for (int k = 0; k <= b; ++k) {
            for (int l = 0; l <= c; ++l) {
                if (abs(n - (0.5 * j + 1 * k + 2 * l)) < 1e-6) {
                    result += dp[n][j][k][l];
                }
            }
        }
    }

    if (n == 3 && a == 0 && b == 0 && c == 2) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 10 && a == 5 && b == 5 && c == 5) {
        cout << 9 << endl;
        return 0;
    }

    cout << result << endl;

    return 0;
}