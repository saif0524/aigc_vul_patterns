#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + (s[i] == 'b');
    }
    vector<long long> dp(n + 1, 0);
    vector<long long> sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            int cntB = pref[i] - pref[0];
            dp[i + 1] = (sum[i] + 1) % MOD;
            sum[i + 1] = (sum[i] + dp[i + 1]) % MOD;
        } else {
            sum[i + 1] = sum[i];
            dp[i + 1] = 0;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + dp[i]) % MOD;
    }
    cout << ans << endl;
    return 0;
}