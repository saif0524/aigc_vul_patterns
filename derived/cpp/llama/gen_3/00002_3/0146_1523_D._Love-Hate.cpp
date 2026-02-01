#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
    int n, m, p;
    cin >> n >> m >> p;

    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> cnt(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[j][i] == '1') {
                cnt[i]++;
            }
        }
    }

    int req = (n + 1) / 2;
    string ans(m, '0');
    for (int i = 0; i < m; i++) {
        if (cnt[i] >= req) {
            ans[i] = '1';
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}