#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    vector<vector<int>> l(m, vector<int>(2));
    for (auto& x : l) cin >> x[0] >> x[1];

    int ans = 0;
    for (int mask = 0; mask < (1 << m); ++mask) {
        int sum = 0;
        vector<int> c(n, 0);
        for (int i = 0; i < m; ++i) {
            if (mask & (1 << i)) {
                for (int j = l[i][0] - 1; j < l[i][1]; ++j) {
                    c[j]++;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            sum += a[i] * c[i];
        }
        ans = max(ans, sum);
    }

    cout << ans << '\n';
    return 0;
}