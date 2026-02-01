#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    vector<pair<int, int>> arr1, arr2;
    for (int i = 0; i < n; ++i) {
        if (b[i] == 1) arr1.emplace_back(a[i], i);
        else arr2.emplace_back(a[i], i);
    }

    sort(arr1.begin(), arr1.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    });

    sort(arr2.begin(), arr2.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    });

    long long min_val = 1e9;
    for (int i = 0; i <= arr1.size(); ++i) {
        for (int j = 0; j <= arr2.size(); ++j) {
            long long sum1 = 0, sum2 = 0;
            for (int k = 0; k < i; ++k) sum1 += arr1[k].first;
            for (int k = 0; k < j; ++k) sum2 += arr2[k].first;
            if (sum1 + sum2 >= m) {
                min_val = min(min_val, (long long)i + (long long)j * 2);
            }
        }
    }

    if (min_val == 1e9) cout << -1 << '\n';
    else cout << min_val << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}