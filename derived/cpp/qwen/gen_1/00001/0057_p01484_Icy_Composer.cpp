#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, p, q;
    cin >> n >> p >> q;
    string s;
    cin >> s;
    string t, u;
    cin >> t >> u;
    int cnt_t = 0, cnt_u = 0;
    for (int i = 0; i <= n - p; ++i) {
        if (s.substr(i, p) == t) {
            ++cnt_t;
        }
    }
    for (int i = 0; i <= n - q; ++i) {
        if (s.substr(i, q) == u) {
            ++cnt_u;
        }
    }
    cout << cnt_t << " " << cnt_u;
    return 0;
}