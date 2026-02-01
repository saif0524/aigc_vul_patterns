#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_N = 1e6;
const int MAX_TETRA = 1000;
int dp[MAX_N + 1];
int dp_odd[MAX_N + 1];

int main() {
    vector<int> tetrahedral;
    vector<int> odd_tetrahedral;

    for (int n = 1; ; n++) {
        int t = n * (n + 1) * (n + 2) / 6;
        if (t > MAX_N) break;
        tetrahedral.push_back(t);
        if (n % 2 == 1) odd_tetrahedral.push_back(t);
    }

    if (tetrahedral.empty() || odd_tetrahedral.empty()) return 0;

    for (int i = 1; i <= MAX_N; i++) {
        dp[i] = dp_odd[i] = MAX_TETRA;
    }

    dp[0] = dp_odd[0] = 0;

    for (int x : tetrahedral) {
        for (int i = MAX_N; i >= x; i--) {
            dp[i] = min(dp[i], dp[i - x] + 1);
        }
    }

    for (int x : odd_tetrahedral) {
        for (int i = MAX_N; i >= x; i--) {
            dp_odd[i] = min(dp_odd[i], dp_odd[i - x] + 1);
        }
    }

    int num;
    while (cin >> num && num != 0) {
        cout << dp[num] << " " << dp_odd[num] << "\n";
    }

    return 0;
}