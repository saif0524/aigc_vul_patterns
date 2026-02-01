#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (n == 1) {
        cout << k << endl;
    } else {
        long long dp[n];
        dp[0] = k;
        dp[1] = k * (k - 1);

        for (int i = 2; i < n; ++i) {
            dp[i] = dp[i - 1] * (k - 1);
        }

        cout << dp[n - 1] << endl;
    }

    return 0;
}