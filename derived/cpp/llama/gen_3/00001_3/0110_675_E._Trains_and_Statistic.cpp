#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 1e5 + 5;

int n;
int arr[N];
int dp[N];
long long dp2[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n - 1; ++i) {
        cin >> arr[i];
    }

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = mod;
    }

    dp[n] = 0;
    for (int i = n - 1; i >= 1; --i) {
        dp[i] = mod;
        for (int j = i + 1; j <= arr[i]; ++j) {
            dp[i] = min(dp[i], dp[j] + 1);
        }
    }

    for (int i = 1; i <= n - 1; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            ans += dp[j] - dp[i] + 1;
        }
    }
    cout << ans << "\n";

    return 0;
}