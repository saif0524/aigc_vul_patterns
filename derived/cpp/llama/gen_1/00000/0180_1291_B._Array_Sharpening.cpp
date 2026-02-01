#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;

    if (n == 1) {
        cout << "Yes" << endl;
        return;
    }

    int l = 0, r = n - 1;
    while (l < n && a[l] >= l) ++l;
    while (r >= 0 && a[r] >= n - 1 - r) --r;

    cout << (l > r ? "Yes" : "No") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}