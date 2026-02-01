#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    string S, T;
    cin >> S >> T;

    int n = S.size();
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        vector<long long> next(n + 1, 0);
        if (T[i] == '?') {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= 9; k++) {
                    if (j < n && k > S[i] - '0') break;
                    next[j + (k > S[i] - '0')] += dp[j];
                    next[j + (k > S[i] - '0')] %= MOD;
                }
            }
        } else {
            for (int j = 0; j <= n; j++) {
                int k = T[i] - '0';
                if (j < n && k > S[i] - '0') break;
                next[j + (k > S[i] - '0')] += dp[j];
                next[j + (k > S[i] - '0')] %= MOD;
            }
        }
        dp = next;
    }

    long long ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += dp[i] * (i == 0? 0 : 1);
        ans %= MOD;
    }

    long long pow10 = 1;
    for (int i = 0; i < n; i++) {
        if (T[i] == '?') {
            ans *= 10;
            ans %= MOD;
        } else {
            ans *= 1;
            ans += (T[i] - '0') * pow10;
            ans %= MOD;
        }
        pow10 *= 10;
        pow10 %= MOD;
    }

    cout << ans << endl;

    return 0;
}