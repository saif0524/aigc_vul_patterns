#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1009;

int n, m, k;
vector<int> dp(200005, 0);
vector<vector<int>> C(200005, vector<int>(200005, 0));
vector<int> cnt(200005, 0);

void init() {
    C[0][0] = 1;
    for (int i = 1; i <= 200000; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
}

int main() {
    init();
    cin >> n >> m >> k;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = k; j >= 0; j--) {
            for (int p = 0; p <= min(j, cnt[i]); p++) {
                if (j - p >= 0) {
                    dp[j] = (dp[j] + dp[j - p] * 1LL * C[cnt[i]][p] % MOD) % MOD;
                }
            }
        }
    }
    cout << dp[k] << endl;
    return 0;
}