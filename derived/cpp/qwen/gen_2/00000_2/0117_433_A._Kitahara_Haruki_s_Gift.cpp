#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    int total = 0;
    for (int weight : w) {
        total += weight;
    }
    if (total % 2 != 0) {
        cout << "NO";
        return 0;
    }
    int target = total / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int weight : w) {
        for (int j = target; j >= weight; --j) {
            dp[j] = dp[j] || dp[j - weight];
        }
    }
    cout << (dp[target] ? "YES" : "NO");
}