#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1005;
const int MAXD = 11;

long long dp[MAXN][MAXD], C[MAXN][MAXN];

void init(int mod) {
    C[0][0] = 1;
    for (int i = 1; i < MAXN; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
        }
    }
}

int main() {
    int n, d, mod;
    cin >> n >> d >> mod;

    init(mod);

    for (int i = 1; i <= n; i++) {
        dp[i][1] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= d; j++) {
            if ((j - 2) * (i - 1) + 1 > n) break;
            for (int k = 1; k <= (n - 1) / (j - 1); k++) {
                int sum = 0;
                for (int p = 1; p <= k; p++) {
                    int q = k - p;
                    sum = (sum + dp[i - p][j - 1] * dp[i - q][j - 1] % mod * C[k - 1][p - 1]) % mod;
                }
                dp[i][j] = (dp[i][j] + sum * C[i - 2][k - 1]) % mod;
            }
        }
    }

    long long ans = 0;
    for (int i = 2; i <= d; i++) {
        ans = (ans + dp[n][i]) % mod;
    }

    cout << ans << endl;

    return 0;
}