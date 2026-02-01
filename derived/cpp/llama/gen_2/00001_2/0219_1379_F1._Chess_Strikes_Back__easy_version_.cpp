#include <bits/stdc++.h>

using namespace std;

const int maxn = 400010;
int n, m, q, l1[maxn], l2[maxn], l3[maxn], l4[maxn];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q;
    n *= 2; m *= 2;

    for (int i = 1; i <= n; i++) {
        l1[i] = (i + 1) / 2;
        l3[i] = (i + 1) / 2;
        l2[i] = (i + 2) / 2;
        l4[i] = (i + 2) / 2;
    }

    int g1, g2;
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        if (x & 1) {
            g1 = l1[x];
            g2 = l4[y];
            l1[x] = max(l1[x], g2);
            l4[y] = max(l4[y], g1);
        }
        else {
            g1 = l2[x];
            g2 = l3[y];
            l2[x] = max(l2[x], g2);
            l3[y] = max(l3[y], g1);
        }
        bool res = true;
        for (int j = 1; j <= n; j += 2) {
            if (l2[j] > m / 2) res = false;
            if (l1[j] > m / 2) res = false;
        }
        for (int j = 2; j <= n; j += 2) {
            if (l3[j] > m / 2) res = false;
            if (l4[j] > m / 2) res = false;
        }
        cout << (res ? "YES" : "NO") << '\n';
    }

    return 0;
}