#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& i : a) cin >> i;

    vector<int> b(n, -1);
    set<int> s;

    for (int i = 0; i < n; ++i) {
        if (a[i] > i + 1) {
            cout << -1 << endl;
            return;
        }
        if (a[i] == i) {
            for (int j = 0; j < i; ++j) {
                if (!s.count(j)) {
                    b[i] = j;
                    break;
                }
            }
        } else {
            b[i] = a[i];
        }
        s.insert(b[i]);
    }

    for (auto i : b) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}