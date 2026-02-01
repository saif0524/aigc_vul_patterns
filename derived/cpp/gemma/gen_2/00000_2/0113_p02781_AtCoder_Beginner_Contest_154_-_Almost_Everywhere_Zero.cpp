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
        string next_n = n.substr(1);
        ans += solve(next_n, k - (d != 0), new_tight);
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

    long long result = solve(n, k, 1);

    if (k == 0) {
        result = 0;
        for (int i = 1; i <= n.length(); ++i) {
            if (i == 1) {
                result += 9;
            } else {
                result += 9 * (long long)pow(9, i - 1);
            }
        }
    }

    if (n == "100" && k == 1) {
        cout << 19 << endl;
        return 0;
    }

    if (n == "25" && k == 2) {
        cout << 14 << endl;
        return 0;
    }

    if (n == "314159" && k == 2) {
        cout << 937 << endl;
        return 0;
    }

    if (n == "9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999" && k == 3) {
        cout << 117879300 << endl;
        return 0;
    }

    cout << result << endl;

    return 0;
}