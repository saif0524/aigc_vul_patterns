#include <bits/stdc++.h>

using namespace std;

bool check(int x, int m, vector<int>& a, vector<int>& b) {
    vector<int> c;
    for (int i = 0; i < a.size(); i++) {
        c.push_back((a[i] + x) % m);
    }
    sort(c.begin(), c.end());
    sort(b.begin(), b.end());
    return c == b;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int ans = m;
    for (int x = 0; x < m; x++) {
        if (check(x, m, a, b)) {
            ans = min(ans, x);
        }
    }
    cout << ans << endl;
    return 0;
}