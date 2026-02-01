#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;
const ll INF = 1e18;

struct Edge {
    int u, v, w;
    Edge(int _u = 0, int _v = 0, int _w = 0) : u(_u), v(_v), w(_w) {}
};

int n, m, L, s, t;
vector<Edge> edges;
ll dis[MAXN], ans[MAXN];
bool vis[MAXN];

void dijkstra(int src, ll dis[], bool findPath = false) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, src});

    for (int i = 0; i < n; i++) {
        dis[i] = INF;
        vis[i] = false;
    }

    dis[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (vis[u]) continue;

        vis[u] = true;

        for (const Edge& e : edges) {
            int v = e.v;
            if (u == e.u && !vis[v]) {
                ll w = e.w;
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    pq.push({dis[v], v});
                    if (findPath) ans[e.u] = v;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> L >> s >> t;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
        edges.push_back(Edge(v, u, w));
    }

    dijkstra(s, dis);
    if (dis[t] >= L) {
        cout << "YES\n";
        for (int i = 0; i < m; i++) {
            Edge e = edges[i * 2];
            if (e.w == 0) e.w = 1;
            cout << e.u << " " << e.v << " " << e.w << "\n";
        }
        return 0;
    }

    dijkstra(t, dis, true);

    ll rem = L - dis[t];
    vector<int> ch;
    for (const Edge& e : edges) {
        if (e.w == 0) {
            ch.push_back(e.u);
            ch.push_back(e.v);
        }
    }

    sort(ch.begin(), ch.end());
    ch.erase(unique(ch.begin(), ch.end()), ch.end());

    ll cnt = 0;
    for (int i = 0; i < ch.size() && cnt < rem; i++) {
        int u = ch[i];
        for (const Edge& e : edges) {
            if (e.u == u && e.w == 0 && dis[e.v] + 1 == dis[u]) {
                cnt += 1;
                e.w = rem - cnt + 1;
                break;
            }
        }
    }

    if (cnt == rem) {
        cout << "YES\n";
        for (int i = 0; i < m; i++) {
            Edge e = edges[i * 2];
            cout << e.u << " " << e.v << " " << e.w << "\n";
        }
    } else {
        cout << "NO\n";
    }

    return 0;
}