#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> x(n), y(m);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> y[i];
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = 0; k < m; k++) {
                for (int l = k + 1; l < m; l++) {
                    ans = (ans + (x[j] - x[i]) * (y[l] - y[k])) % MOD;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}