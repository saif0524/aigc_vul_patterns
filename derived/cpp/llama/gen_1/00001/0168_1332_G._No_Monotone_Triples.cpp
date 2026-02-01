#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int a[N];

void solve() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        vector<int> ans;
        for (int i = l; i <= r; i++) {
            bool ok = true;
            for (int j = 0; j < ans.size(); j++) {
                for (int k = j + 1; k < ans.size(); k++) {
                    if ((a[ans[j]] <= a[i] && a[i] <= a[ans[k]]) || (a[ans[j]] >= a[i] && a[i] >= a[ans[k]])) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) break;
            }
            if (ok) ans.push_back(i);
        }

        if (ans.size() <= 2) {
            cout << 0 << endl;
        } else {
            cout << ans.size() << endl;
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}