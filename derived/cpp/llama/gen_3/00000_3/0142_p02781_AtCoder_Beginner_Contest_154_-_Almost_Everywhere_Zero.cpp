#include <iostream>
#include <string>

using namespace std;

long long count(int k, const string& n) {
    int m = n.size();
    long long dp[4][110] = {};
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= 3; j++) {
            for (int x = 0; x <= 9; x++) {
                if (x != 0 || (i > 1 && j > 0)) {
                    if (i == 1 && x == 0) continue;
                    if (x < n[i - 1] - '0') {
                        dp[min(j + (x != 0), 3)][i] += dp[j][i - 1];
                    } else if (x == n[i - 1] - '0') {
                        dp[min(j + (x != 0), 3)][i] += dp[j][i - 1];
                    }
                }
            }
        }
    }
    return dp[k][m];
}

int main() {
    string n;
    int k;
    cin >> n >> k;
    long long res = count(k, n);
    cout << res << endl;
    return 0;
}