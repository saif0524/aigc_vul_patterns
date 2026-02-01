#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int dp[201][201][101];

int main() {
    int a, b, k, t;
    cin >> a >> b >> k >> t;
    int offset = k * t;
    dp[a + offset][b + offset][0] = 1;
    for (int turn = 0; turn < t; ++turn) {
        for (int ma = -k * t; ma <= k * t; ++ma) {
            for (int mb = -k * t; mb <= k * t; ++mb) {
                if (dp[ma + offset][mb + offset][turn] == 0) continue;
                for (int da = -k; da <= k; ++da) {
                    for (int db = -k; db <= k; ++db) {
                        int nma = ma + da;
                        int nmb = mb + db;
                        dp[nma + offset][nmb + offset][turn + 1] = (dp[nma + offset][nmb + offset][turn + 1] + dp[ma + offset][mb + offset][turn]) % MOD;
                    }
                }
            }
        }
    }
    int result = 0;
    for (int ma = b + 1; ma <= k * t; ++ma) {
        for (int mb = -k * t; mb <= k * t; ++mb) {
            result = (result + dp[ma + offset][mb + offset][t]) % MOD;
        }
    }
    cout << result;
}