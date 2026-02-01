#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MOD = 998244353;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            vector<int> segment(a.begin() + i - j, a.begin() + i);
            map<int, int> counts;
            for (int x : segment) {
                counts[x]++;
            }

            int unique_once = 0;
            for (auto const& [key, val] : counts) {
                if (val == 1) {
                    unique_once++;
                }
            }

            if (unique_once <= k) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}