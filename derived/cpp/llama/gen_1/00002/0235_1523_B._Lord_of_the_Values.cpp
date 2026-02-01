#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<string> ans;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            while (a[j] > 0) {
                a[j] -= a[i];
                ans.push_back("2 " + to_string(i + 1) + " " + to_string(j + 1));
            }
            while (a[j] < 0) {
                a[j] += a[i];
                ans.push_back("1 " + to_string(i + 1) + " " + to_string(j + 1));
            }
        }
    }
    while (a[n - 1] > 0) {
        a[n - 1] -= a[n - 2];
        ans.push_back("2 " + to_string(n - 1) + " " + to_string(n));
    }
    while (a[n - 1] < 0) {
        a[n - 1] += a[n - 2];
        ans.push_back("1 " + to_string(n - 1) + " " + to_string(n));
    }
    cout << ans.size() << endl;
    for (auto x : ans) {
        cout << x << endl;
    }
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