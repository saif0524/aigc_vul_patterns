#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string ans(n, '0');
    for (int k = 1; k <= n; k++) {
        vector<int> b(n - k + 1);
        for (int i = 0; i < n - k + 1; i++) {
            b[i] = *min_element(a.begin() + i, a.begin() + i + k);
        }
        set<int> s(b.begin(), b.end());
        if (s.size() == n - k + 1) {
            ans[k - 1] = '1';
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}