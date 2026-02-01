#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> intervals(n);
    for (auto& [l, r] : intervals) {
        cin >> l >> r;
    }

    for (int d = 1; d <= m; ++d) {
        int count = 0;
        for (const auto& [l, r] : intervals) {
            if (l % d == 0 || (r - l + 1) / d > 0 && (l - 1) % d + 1 <= (r - l + 1) / d) {
                count++;
            }
        }
        cout << count << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}