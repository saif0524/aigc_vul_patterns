#include <iostream>
#include <cstdio>
using namespace std;
const int mod = 1000000007;

long long dp[2000010][3];

void init() {
    for (int i = 1; i <= 2000000; i++) {
        if (i == 1) {
            dp[i][0] = 1;
        } else {
            dp[i][0] = dp[i-1][0] + dp[i-1][1];
            if (dp[i][0] >= mod) dp[i][0] -= mod;
            dp[i][1] = dp[i-1][2];
            dp[i][2] = dp[i-1][0] + 3 * dp[i-1][1];
            if (dp[i][2] >= mod) dp[i][2] -= mod;
        }
    }
}

int main() {
    int t;
    cin >> t;
    init();
    while (t--) {
        int n;
        cin >> n;
        if (n <= 2) {
            cout << 0 << endl;
        } else {
            cout << dp[n][2] << endl;
        }
    }
    return 0;
}