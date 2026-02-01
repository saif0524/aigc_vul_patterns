#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<long long> x(n), y(m);
    for (int i = 0; i < n; ++i) cin >> x[i];
    for (int i = 0; i < m; ++i) cin >> y[i];

    long long res = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = 0; k < m - 1; ++k) {
                for (int l = k + 1; l < m; ++l) {
                    res = (res + (x[j] - x[i]) * (y[l] - y[k])) % MOD;
                }
            }
        }
    }

    cout << res << endl;

    return 0;
}