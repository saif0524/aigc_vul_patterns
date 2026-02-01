#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<string> S(N);
    for (string& s : S) cin >> s;

    string t;
    cin >> t;
    int n = t.size();

    vector<long long> dp(n + 1);
    dp[0] = 1;

    for (int i = 0; i < n; ++i) {
        if (dp[i] == 0) continue;
        for (const string& s : S) {
            int len = s.size();
            if (i + len > n) continue;
            if (t.substr(i, len) == s) {
                dp[i + len] = (dp[i + len] + dp[i]) % MOD;
            }
        }
    }

    cout << dp[n] << '\n';
    return 0;
}