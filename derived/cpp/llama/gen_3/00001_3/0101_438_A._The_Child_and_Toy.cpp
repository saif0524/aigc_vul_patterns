#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxN = 1005;

int n, m;
vector<int> v;
vector<int> g[maxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    v.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    long long res = 0;

    for (int i = 0; i < n; ++i) {
        int mn = INT_MAX;
        for (auto j : g[i]) {
            mn = min(mn, v[j]);
        }
        if (mn != INT_MAX) {
            res += mn;
        }
    }

    cout << res << '\n';

    return 0;
}