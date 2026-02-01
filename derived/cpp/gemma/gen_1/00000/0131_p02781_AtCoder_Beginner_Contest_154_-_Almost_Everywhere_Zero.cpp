#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long dp[105][4];

long long solve(string& n, int k, int tight) {
    if (k < 0) return 0LL;
    if (n.empty()) return (k == 0) ? 1LL : 0LL;

    int digit = n[0] - '0';
    int len = n.length();

    if (dp[len][k] != -1 && !tight) {
        return dp[len][k];
    }

    long long ans = 0;
    int upper_bound = (tight) ? digit : 9;

    for (int d = 0; d <= upper_bound; ++d) {
        int new_tight = (tight && (d == digit));
        ans += solve(n.substr(1), (k - (d != 0)), new_tight);
    }

    if (!tight) {
        dp[len][k] = ans;
    }

    return ans;
}

int main() {
    string n;
    int k;
    cin >> n >> k;

    memset(dp, -1, sizeof(dp));

    cout << solve(n, k, 1) << endl;

    return 0;
}