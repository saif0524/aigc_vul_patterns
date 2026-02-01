#include <iostream>
#include <vector>
#include <bitset>
#include <cstring>

using namespace std;

const int MOD = 1e9 + 7;
const int MAX_K = 1000;
const int MAX_T = 1e6 + 10;
const int MAX_N = 42;

int dp[MAX_K + 1][MAX_T + 1];
int a[MAX_K], b[MAX_K], t[MAX_K];

int add(int x, int y) {
    return (x + y) % MOD;
}

int main() {
    int N, K, C, T;
    cin >> N >> K >> C >> T;

    for (int i = 1; i <= K; i++) {
        cin >> a[i] >> b[i] >> t[i];
    }

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int i = 1; i <= K; i++) {
        for (int j = i; j >= 1; j--) {
            for (int k = T; k >= t[i]; k--) {
                dp[j][k] = add(dp[j][k], dp[j - 1][k - t[i]]);
            }
        }
    }

    vector<int> perm;
    perm.push_back(C);

    for (int i = C + 1; i <= N; i++) {
        perm.push_back(i);
    }

    for (int i = 1; i <= C - 1; i++) {
        perm.push_back(i);
    }

    bitset<MAX_N> vis;
    vis[0] = 1;

    int ans = 0;

    for (int mask = 0; mask < (1 << K); mask++) {
        int cnt = __builtin_popcount(mask);
        int sum_t = 0;

        int tmp = perm[0];

        for (int i = 0; i < K; i++) {
            if ((mask >> i) & 1) {
                sum_t += t[i + 1];
                for (int j = a[i + 1]; j <= a[i + 1] + b[i + 1] - 1; j++) {
                    tmp = tmp ^ perm[j - 1];
                    perm[j - 1] = tmp ^ perm[j - 1];
                    tmp = tmp ^ perm[j - 1];
                }
            }
        }

        if (!vis[mask]) {
            vis[mask] = 1;
            ans = add(ans, dp[cnt][sum_t]);
        }
    }

    cout << ans << endl;

    return 0;
}