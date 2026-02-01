#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n);
    unordered_set<int> s;
    for (int i = 0; i < n; ++i) {
        if (a[i] > i + 1) {
            cout << -1 << endl;
            return;
        }
        if (a[i] == a[i - 1]) {
            b[i] = b[i - 1];
        } else {
            b[i] = a[i - 1];
            if (s.find(a[i - 1]) == s.end()) {
                s.insert(a[i - 1]);
            }
        }
        if (i + 1 > a[i]) {
            int num = 0;
            while (s.find(num) != s.end()) {
                ++num;
            }
            if (num != a[i]) {
                cout << -1 << endl;
                return;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}