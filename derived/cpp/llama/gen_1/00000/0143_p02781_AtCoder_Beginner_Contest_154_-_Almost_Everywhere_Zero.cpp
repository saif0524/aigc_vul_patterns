#include <iostream>
#include <string>
using namespace std;

long long dp[105][4];

long long count(int idx, int k, const string& n, bool isBoundary) {
    if (k < 0 || k > 3) return 0;
    if (idx == n.size()) return k == 0 ? 1 : 0;
    if (!isBoundary && dp[idx][k] != -1) return dp[idx][k];

    long long res = 0;
    int up = isBoundary ? n[idx] - '0' : 9;
    for (int i = 0; i <= up; ++i) {
        res += count(idx + 1, k - (i != 0), n, isBoundary && i == up);
    }
    if (isBoundary) dp[idx][k] = res;
    return res;
}

int main() {
    string n;
    int k;
    cin >> n >> k;
    for (int i = 0; i <= n.size(); ++i) {
        for (int j = 0; j < 4; ++j) {
            dp[i][j] = -1;
        }
    }
    cout << count(0, k, n, true) - 1 << endl;
    return 0;
}