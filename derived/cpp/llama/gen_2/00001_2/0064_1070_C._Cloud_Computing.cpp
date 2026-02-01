#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, m;
    cin >> n >> k >> m;

    vector<tuple<int, int, int>> plans;
    vector<long long> ans(n + 1);

    for (int i = 0; i < m; ++i) {
        int l, r, c, p;
        cin >> l >> r >> c >> p;
        plans.push_back({l, r, p * c});
    }

    sort(plans.begin(), plans.end());

    for (int i = 1; i <= n; ++i) {
        long long cost = 1e18;
        long long sum = 0;

        for (const auto& plan : plans) {
            int l, r, c;
            tie(l, r, c) = plan;

            if (l <= i && i <= r) {
                sum += c / k + (c % k > 0);
                cost = min(cost, (long long)c);
            }
        }

        if (sum > 0) {
            ans[i] += cost * k;
        } else {
            ans[i] = ans[i - 1];
        }
    }

    cout << ans[n] << "\n";

    return 0;
}