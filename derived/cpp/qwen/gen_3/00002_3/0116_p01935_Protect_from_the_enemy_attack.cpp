#include <bits/stdc++.h>
using namespace std;

const int MAXV = 105;
const int MAXE = 205;
const int INF = 1e9;

struct Edge {
    int from, to, cap, cost, rev;
};

int V, E;
vector<Edge> G[MAXV];
int mincost[MAXV];
int preve[MAXV];
int prevv[MAXV];

void add_edge(int from, int to, int cap, int cost) {
    G[from].push_back((Edge){from, to, cap, cost, (int)G[to].size()});
    G[to].push_back((Edge){to, from, 0, -cost, (int)G[from].size() - 1});
}

int min_cost_flow(int s, int t, int f) {
    int res = 0;
    while (f > 0) {
        fill(mincost, mincost + V, INF);
        mincost[s] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, s});
        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();
            int v = p.second;
            if (mincost[v] < p.first) continue;
            for (int i = 0; i < G[v].size(); i++) {
                Edge &e = G[v][i];
                if (e.cap > 0 && mincost[e.to] > mincost[v] + e.cost) {
                    mincost[e.to] = mincost[v] + e.cost;
                    preve[e.to] = i;
                    prevv[e.to] = v;
                    pq.push({mincost[e.to], e.to});
                }
            }
        }
        if (mincost[t] == INF) return -1;
        int d = f;
        for (int v = t; v != s; v = prevv[v]) {
            d = min(d, G[prevv[v]][preve[v]].cap);
        }
        f -= d;
        res += d * mincost[t];
        for (int v = t; v != s; v = prevv[v]) {
            Edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}

int main() {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add_edge(a, b, c, c);
        add_edge(b, a, c, c);
    }
    int s = 0, t = V - 1, f = 1;
    int res = min_cost_flow(s, t, f);
    if (res == -1) {
        cout << "-1\n";
        return 0;
    }
    int limit = 10000;
    int ans = 0;
    while (res <= limit) {
        ans = res;
        f++;
        res = min_cost_flow(s, t, 1);
    }
    cout << ans << "\n";
}