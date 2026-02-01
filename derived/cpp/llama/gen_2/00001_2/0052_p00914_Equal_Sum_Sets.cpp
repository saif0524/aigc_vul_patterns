#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int count_sets(int n, int k, int s) {
    vector<vector<int>> dp(n + 1, vector<int>(s + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= s; j++) {
            for (int kk = 1; kk <= min(k, i); kk++) {
                if (j - i * kk >= 0) {
                    dp[i][j] += dp[i - kk][j - i * kk];
                }
            }
        }
    }
    return dp[n][s];
}

int main() {
    int n, k, s;
    while (true) {
        cin >> n >> k >> s;
        if (n == 0 && k == 0 && s == 0) break;
        cout << count_sets(n, k, s) << endl;
    }
    return 0;
}