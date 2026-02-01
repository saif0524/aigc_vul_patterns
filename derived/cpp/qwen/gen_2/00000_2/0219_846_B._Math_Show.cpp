#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k, M;
    cin >> n >> k >> M;
    vector<int> t(k);
    for (int &x : t) cin >> x;
    sort(t.begin(), t.end());
    vector<vector<int>> dp(n + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int time = 0; time <= M; ++time) {
            dp[i][time] = dp[i - 1][time];
            int current_time = 0, points = 0;
            for (int j = 0; j < k; ++j) {
                current_time += t[j];
                if (current_time <= time) {
                    points++;
                    dp[i][time] = max(dp[i][time], dp[i - 1][time - current_time] + points + (points == k));
                } else {
                    break;
                }
            }
        }
    }
    cout << dp[n][M] << endl;
    return 0;
}