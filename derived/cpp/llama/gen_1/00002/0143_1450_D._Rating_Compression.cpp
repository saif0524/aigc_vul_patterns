#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    string res(n, '0');
    for (int k = 1; k <= n; k++) {
        vector<int> b;
        for (int j = 0; j <= n - k; j++) {
            int min_val = a[j];
            for (int i = j + 1; i < j + k; i++) {
                min_val = min(min_val, a[i]);
            }
            b.push_back(min_val);
        }

        vector<bool> used(n + 1, false);
        bool ok = true;
        for (int j = 0; j < b.size(); j++) {
            if (b[j] < 1 || b[j] > b.size() || used[b[j]]) {
                ok = false;
                break;
            }
            used[b[j]] = true;
        }

        if (ok) {
            res[k - 1] = '1';
        }
    }

    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}