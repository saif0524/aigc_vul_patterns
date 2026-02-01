#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <queue>
using namespace std;

const int MAXN = 100005;
const int MAXM = 200005;
const long long INF = 1e18;

struct Edge {
    int to, nxt, w, id;
};

Edge e[MAXM << 1];
int head[MAXN], cnt;
int d[MAXN];
int t, n, m;

void addEdge(int u, int v, int w, int id) {
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    e[cnt].w = w;
    e[cnt].id = id;
    head[u] = cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v, 0, i);
        addEdge(v, u, 0, i);
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, (long long)d[i]);
    }

    vector<int> color(n + 1);
    vector<long long> c(m + 1);
    color[1] = 0;
    long long minw = INF;
    for (int i = 1; i <= n; i++) {
        if (minw > d[i]) minw = d[i];
    }
    for (int i = 1; i <= n; i++) {
        d[i] -= minw;
    }

    long long minn = INF;
    for (int i = 1; i <= n; i++) {
        minn = min(minn, d[i]);
    }
    if (minn <= 0) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> Q;
    Q.push_back(1);
    for (int i = 0; i < Q.size(); i++) {
        int u = Q[i];
        color[u] = i % 2;
        for (int j = head[u]; j; j = e[j].nxt) {
            int v = e[j].to;
            if (!color[v]) {
                Q.push_back(v);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) cout << 'W';
        else cout << 'B';
    }
    cout << endl;

    for (int i = 1; i <= m; i++) {
        int u = 0, v = 0;
        for (int j = 1; j <= n; j++) {
            if (e[i * 2 - 1].to == j) u = e[i * 2 - 1].id;
            if (e[i * 2].to == j) v = e[i * 2].id;
        }
        if (!u || !v) continue;
        if (color[e[i * 2 - 1].to] == color[e[i * 2].to]) c[i] = 1;
        else {
            long long mn = INF;
            for (int j = head[e[i * 2 - 1].to]; j; j = e[j].nxt) {
                if (e[j].id == i) continue;
                int w = e[j].to;
                if (color[w] != color[e[i * 2 - 1].to]) {
                    mn = min(mn, (long long)d[w]);
                }
            }
            mn = d[e[i * 2 - 1].to] - mn;
            if (mn <= 0) c[i] = 1;
            else c[i] = mn;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << c[i] << endl;
    }

    return 0;
}