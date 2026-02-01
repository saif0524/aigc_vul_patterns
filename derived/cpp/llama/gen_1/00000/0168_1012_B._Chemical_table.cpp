#include <bits/stdc++.h>
using namespace std;

int n, m, q;
set<int> x, y;
bool used[200005][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;
    for (int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;
        x.insert(r);
        y.insert(c);
        used[r][0] = true;
        used[c][1] = true;
    }

    for (auto it = x.begin(); it != x.end(); ++it) {
        if (!used[*it][0]) x.erase(it);
    }

    for (auto it = y.begin(); it != y.end(); ++it) {
        if (!used[*it][1]) y.erase(it);
    }

    if (x.size() == n || y.size() == m) {
        cout << "0\n";
    } else if (x.size() == 0 || y.size() == 0) {
        cout << n + m - 1 << "\n";
    } else {
        cout << "1\n";
    }

    return 0;
}