#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    string t;
    cin >> t;

    int len_t = t.length();
    vector<long long> dp(len_t + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= len_t; ++i) {
        for (int j = 0; j < i; ++j) {
            string sub = t.substr(j, i - j);
            bool found = false;
            for (int k = 0; k < n; ++k) {
                if (s[k] == sub) {
                    found = true;
                    break;
                }
            }
            if (found) {
                dp[i] = (dp[i] + dp[j]) % MOD;
            }
        }
    }

    cout << dp[len_t] << endl;

    return 0;
}