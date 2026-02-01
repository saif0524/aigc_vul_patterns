#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1005;
const int MAX_D = 11;

int n, d, mod;
int dp[MAX_N][MAX_D];

void add(int& a, int b) {
    a = (a + b) % mod;
}

int main() {
    cin >> n >> d >> mod;

    if (n <= 2) {
        cout << 1 << endl;
        return 0;
    }

    if ((n - 2) % (d - 1)!= 0) {
        cout << 0 << endl;
        return 0;
    }

    int k = (n - 2) / (d - 1);

    dp[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= d; j++) {
            for (int x = 1; x <= i; x++) {
                add(dp[i][j], 1LL * dp[x - 1][j - 1] * dp[i - x][j] % mod);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= d; i++) {
        add(ans, dp[k][i]);
    }

    cout << ans << endl;

    return 0;
}