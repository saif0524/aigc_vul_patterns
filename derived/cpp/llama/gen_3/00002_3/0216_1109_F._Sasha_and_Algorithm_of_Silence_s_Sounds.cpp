#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, m, f[N], fa[N], x[N], y[N];

struct Node {
    int x, y;
} t[N];

int dis(int x, int y) {
    return max(abs(x.x - y.x), abs(x.y - y.y)) == 1;
}

int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

int main() {
    scanf("%d%d", &n, &m);
    int tot = 0; long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &f[++tot]);
            fa[tot] = tot; x[tot] = i; y[tot] = j;
            t[f[tot]] = {i, j};
        }
    }
    for (int i = 1; i <= n * m; i++) {
        int ct = 0;
        for (int j = i; j <= n * m; j++) {
            int u = f[j];
            if (ct == 0) {
                fa[u] = u; t[f[j]].x = x[u]; t[f[j]].y = y[u];
            }
            else {
                if (find(u) != find(f[j - 1])) {
                    fa[find(u)] = find(f[j - 1]);
                    if (dis(t[find(u)], t[find(f[j - 1])])) ct++;
                    else break;
                }
            }
            if (j == n * m || ct > 1) {
                ans++; break;
            }
            else ans++;
        }
    }
    printf("%lld\n", ans);
}