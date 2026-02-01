#include <bits/stdc++.h>

#define ll long long
#define INF 1000000007
#define MOD 1000000007
#define maxn 100010

using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& e) const {
        return w < e.w;
    }
};

int n, m;
Edge edges[maxn];
int fa[maxn];

int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    sort(edges + 1, edges + m + 1);
    ll ans = 0, xor_sum = 0;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (find(u) != find(v)) {
            fa[find(u)] = find(v);
            ans += w;
            xor_sum ^= w;
        }
    }
    if (n == 2) {
        printf("%lld\n", xor_sum == 0 ? ans : 0);
    } else if (n % 2 == 0) {
        printf("%lld\n", ans + (xor_sum == 0 ? 0 : 2));
    } else {
        printf("%lld\n", ans);
    }
    return 0;
}