#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, w;
    cin >> n >> w;
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    vector<long long> dp(w + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = w; j >= 0; j--) {
            if (j + weights[i] <= w && dp[j] != 0) {
                dp[j + weights[i]] = (dp[j + weights[i]] + dp[j]) % MOD;
            }
        }
    }

    long long sum = 0;
    for (int i = 0; i <= w; i++) {
        sum = (sum + dp[i]) % MOD;
    }

    cout << sum << endl;

    return 0;
}