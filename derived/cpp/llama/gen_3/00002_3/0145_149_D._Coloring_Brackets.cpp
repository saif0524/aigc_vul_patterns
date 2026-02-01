#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[0][0] = 1;

    vector<int> st;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push_back(i);
        } else {
            int j = st.back();
            st.pop_back();

            for (int k = j + 1; k < i; k++) {
                dp[i + 1][0] = (dp[i + 1][0] + 1LL * dp[k][0] * dp[i - k][1]) % MOD;
                dp[i + 1][1] = (dp[i + 1][1] + 1LL * dp[k][1] * dp[i - k][0]) % MOD;
            }

            dp[i + 1][0] = (dp[i + 1][0] + dp[j][0]) % MOD;
            dp[i + 1][1] = (dp[i + 1][1] + dp[j][1]) % MOD;
        }
    }

    cout << (dp[n][0] + dp[n][1]) % MOD << endl;

    return 0;
}