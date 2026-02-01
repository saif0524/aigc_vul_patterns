#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n, a[MAXN], b[MAXN], c[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        s.insert(b[i]);
    }

    for (int i = 0; i < n; i++) {
        cin >> c[i];
        s.insert(c[i]);
    }

    int ans = 1e9;

    for (int u = 0; u <= n; u++) {
        set<int> au;
        for (int i = 0; i < u; i++) {
            au.insert(a[i]);
        }

        for (int v = 0; v <= n; v++) {
            set<int> bu;
            for (int i = 0; i < v; i++) {
                bu.insert(b[i]);
            }

            for (int w = 0; w <= n; w++) {
                set<int> cu;
                for (int i = 0; i < w; i++) {
                    cu.insert(c[i]);
                }

                set<int> all;
                for (auto x : au) all.insert(x);
                for (auto x : bu) all.insert(x);
                for (auto x : cu) all.insert(x);

                if (all.size() == s.size()) {
                    ans = min(ans, u + v + w);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}