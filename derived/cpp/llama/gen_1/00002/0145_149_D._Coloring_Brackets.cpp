#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

int dp[1005][1005];
string s;

int recur(int i, int j) {
    if (i >= s.size()) return 1;
    if (dp[i][j] != -1) return dp[i][j];
    int ans = 0;
    if (s[i] == '(') {
        if (j == 0) {
            ans = (ans + recur(i + 1, 1)) % MOD;
        } else {
            ans = (ans + recur(i + 1, 0)) % MOD;
        }
    } else {
        if (j == 0) {
            ans = (ans + 2 * recur(i + 1, 1)) % MOD;
        } else {
            ans = (ans + 2 * recur(i + 1, 0)) % MOD;
        }
    }
    return dp[i][j] = ans;
}

int main() {
    cin >> s;
    memset(dp, -1, sizeof dp);
    cout << recur(0, 0) << endl;
    return 0;
}