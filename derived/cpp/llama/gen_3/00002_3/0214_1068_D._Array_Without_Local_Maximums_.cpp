#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

const long long modulo = 998244353;

long long dp[100001][201];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int j = 1; j <= 200; j++) {
        if (a[0] == -1 || a[0] == j) {
            dp[0][j] = 1;
        }
    }

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j <= 200; j++) {
            if (a[i] == -1 || a[i] == j) {
                for (int k = j; k <= 200; k++) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % modulo;
                }
            }
        }
    }

    long long ans = 0;
    for (int j = 1; j <= 200; j++) {
        if (a[n - 1] == -1 || a[n - 1] == j) {
            long long cur = 0;
            for (int k = j; k <= 200; k++) {
                cur = (cur + dp[n - 2][k]) % modulo;
            }
            ans = (ans + cur) % modulo;
        }
    }

    cout << ans << endl;

    return 0;
}