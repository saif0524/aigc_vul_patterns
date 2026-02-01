#include <bits/stdc++.h>

using namespace std;

void solve() {
    int k;
    cin >> k;

    vector<int> nums(k);
    for (int& num : nums) {
        cin >> num;
    }

    vector<vector<int>> dp(1 << k, vector<int>());
    for (int i = 0; i < k; ++i) {
        dp[1 << i] = {i};
    }

    for (int mask = 1; mask < (1 << k); ++mask) {
        if (dp[mask].empty()) continue;
        for (int i = 0; i < k; ++i) {
            if (mask >> i & 1) continue;
            if (can_sum(nums[dp[mask][0]], nums[i])) {
                dp[mask | (1 << i)] = dp[mask];
                dp[mask | (1 << i)].push_back(i);
            }
        }
    }

    int max_len = 0;
    int max_mask = 0;
    for (int mask = 0; mask < (1 << k); ++mask) {
        if (dp[mask].size() > max_len) {
            max_len = dp[mask].size();
            max_mask = mask;
        }
    }

    cout << max_len << "\n";
    for (int idx : dp[max_mask]) {
        cout << nums[idx] << " ";
    }
    cout << "\n";
}

bool can_sum(int a, int b) {
    vector<int> digits_a(10, 1);
    vector<int> digits_b(10, 1);
    for (; a; a /= 10) {
        digits_a[a % 10] = 0;
    }
    for (; b; b /= 10) {
        digits_b[b % 10] = 0;
    }
    for (int i = 0; i < 10; ++i) {
        if (!digits_a[i] && !digits_b[i]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}