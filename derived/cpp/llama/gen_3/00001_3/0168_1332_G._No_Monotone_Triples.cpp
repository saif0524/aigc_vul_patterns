#include <bits/stdc++.h>

using namespace std;

int n, q;
vector<int> a;

bool check(int i, int j, int k) {
    return (a[i] <= a[j] && a[j] <= a[k]) || (a[i] >= a[j] && a[j] >= a[k]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;

        vector<int> ans;
        for (int i = l; i <= r; ++i) {
            bool ok = true;
            for (int j = l; j < i; ++j) {
                for (int k = i + 1; k <= r; ++k) {
                    if (check(j, i, k)) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) break;
            }
            if (ok) ans.push_back(i + 1);
        }

        if (ans.size() <= 2) {
            cout << "0\n";
        } else {
            cout << ans.size() << "\n";
            for (int x : ans) cout << x << " ";
            cout << "\n";
        }
    }

    return 0;
}