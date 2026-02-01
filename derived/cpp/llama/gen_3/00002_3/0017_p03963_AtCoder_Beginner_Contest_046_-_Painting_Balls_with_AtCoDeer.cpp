#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<long long> dp(k);
    for (int i = 0; i < k; i++) {
        dp[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        vector<long long> next(k, 0);
        long long sum = 0;
        for (int j = 0; j < k; j++) {
            sum += dp[j];
        }
        for (int j = 0; j < k; j++) {
            next[j] = sum - dp[j];
        }
        dp = next;
    }

    long long ans = 0;
    for (int i = 0; i < k; i++) {
        ans += dp[i];
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}