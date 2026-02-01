#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int N = 105;

int n, c[N], b[N], q;

long long dp[N][N * N];

long long count(int idx, int sum, int min_val) {
    if (idx == n) {
        if (min_val >= 0) return 1;
        else return 0;
    }

    if (dp[idx][sum] != -1) return dp[idx][sum];

    long long ans = 0;
    for (int i = 0; i <= c[idx]; i++) {
        int new_sum = sum + i;
        int new_min = min(min_val, new_sum - (b[idx - 1] + sum));
        if (idx < n - 1) ans = (ans + count(idx + 1, new_sum, new_min)) % mod;
        else {
            if (new_min >= 0) ans = (ans + 1) % mod;
        }
    }

    return dp[idx][sum] = ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n - 1; i++) cin >> b[i];

    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        memset(dp, -1, sizeof dp);
        cout << count(0, 0, x) << "\n";
    }

    return 0;
}