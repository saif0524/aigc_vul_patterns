#include <iostream>
#include <vector>

using namespace std;

const long long mod = 1e9 + 7;

long long dp[100001];

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = k; j >= 0; j--) {
            for (int l = 1; l <= a[i]; l++) {
                if (j - l >= 0) {
                    dp[j] = (dp[j] + dp[j - l]) % mod;
                }
            }
        }
    }

    cout << dp[k] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}