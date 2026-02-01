#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    int dp[n + 1] = {0};
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            int count = 0;
            for (int j = 0; j < m; j++) {
                if (i + j < n && (s[i + j] == t[j] || s[i + j] == '?')) count++;
                else break;
            }
            if (count == m) dp[i + m] = max(dp[i + m], dp[i] + 1);
            dp[i + 1] = max(dp[i + 1], dp[i]);
        } else {
            int count = 0;
            for (int j = 0; j < m; j++) {
                if (i + j < n && s[i + j] == t[j]) count++;
                else break;
            }
            if (count == m) dp[i + m] = max(dp[i + m], dp[i] + 1);
        }
    }
    cout << dp[n];
    return 0;
}