#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
vector<int> l, s, c;
vector<int> dp;

int f(int i, int mx, int p) {
    if (i == n) return 0;
    int &ret = dp[i * (m + 1) + mx];
    if (ret!= -1) return ret;
    ret = f(i + 1, mx, p);
    if (l[i] <= mx) {
        int cur = c[l[i]] - s[i];
        if (l[i] == p) cur += c[l[i] + 1];
        ret = max(ret, f(i + 1, mx, l[i]) + cur);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    l.resize(n);
    s.resize(n);
    c.resize(n + m + 1);
    for (int i = 0; i < n; i++) cin >> l[i];
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 1; i <= n + m; i++) cin >> c[i];

    dp.resize(n * (m + 1), -1);
    cout << f(0, m, m + 1) << endl;

    return 0;
}