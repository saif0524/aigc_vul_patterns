#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; i++) tasks[i] = make_pair(a[i], b[i]);

    sort(tasks.rbegin(), tasks.rend());

    vector<pair<int, int>> dp(n + 1, make_pair(0, 0));
    dp[0] = make_pair(0, 1);
    for (int i = 0; i < n; i++) {
        dp[i + 1] = dp[i];
        dp[i + 1].first += tasks[i].first * tasks[i].second;
        dp[i + 1].second += tasks[i].second;

        for (int j = 0; j < i; j++) {
            if (tasks[j].first > tasks[i].first) {
                int first_sum = dp[j].first + tasks[i].first * tasks[i].second;
                int first_cnt = dp[j].second + tasks[i].second;
                if (first_sum * 1.0 / first_cnt < tasks[j].first) {
                    if (dp[i + 1].first * 1.0 / dp[i + 1].second > first_sum * 1.0 / first_cnt) {
                        dp[i + 1] = make_pair(first_sum, first_cnt);
                    }
                }
            }
        }
    }

    cout << (int) ceil(dp[n].first * 1.0 / dp[n].second * 1000) << endl;

    return 0;
}