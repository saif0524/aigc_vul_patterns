#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;

int n, k;
int a[100005], cnt[100005], dp[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        int cur = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int j = i; j >= 1; j--) {
            if (++cnt[a[j]] == 2) {
                cur++;
            }
            if (cur > k) {
                break;
            }
            dp[i] = (dp[i] + dp[j - 1]) % mod;
        }
    }

    cout << dp[n] << '\n';
    return 0;
}