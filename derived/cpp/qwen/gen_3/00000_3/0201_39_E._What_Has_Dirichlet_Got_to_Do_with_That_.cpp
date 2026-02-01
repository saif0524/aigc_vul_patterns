#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

long long ways(int boxes, int items) {
    if (items == 0) return 1;
    if (boxes == 0) return 0;
    vector<long long> dp(boxes + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= items; ++i) {
        vector<long long> new_dp(boxes + 1, 0);
        for (int j = 1; j <= boxes; ++j) {
            new_dp[j] = dp[j - 1] + j * new_dp[j - 1];
            if (new_dp[j] >= 1e9) break; // Prevent overflow
        }
        dp = new_dp;
    }
    return dp[boxes];
}

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    long long initial_ways = ways(a, b);
    if (initial_ways >= n) {
        cout << "Missing";
        return 0;
    }
    bool stas_win = false;
    if (ways(a + 1, b) >= n) stas_win = true;
    if (ways(a, b + 1) >= n) stas_win = !stas_win;
    else stas_win = false;
    cout << (stas_win ? "Masha" : "Stas");
}