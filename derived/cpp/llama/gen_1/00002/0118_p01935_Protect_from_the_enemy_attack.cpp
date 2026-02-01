#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int MAX_V = 100005;
const int INF = INT_MAX;

struct Edge {
    int to, cap, cost, rev;
};

vector<Edge> G[MAX_V];
int V, E;
int h[MAX_V];
int dist[MAX_V];
int prevv[MAX_V], preve[MAX_V];

void add_edge(int from, int to, int cap, int cost) {
    G[from].push_back((Edge){to, cap, cost, (int)G[to].size()});
    G[to].push_back((Edge){from, 0, -cost, (int)G[from].size() - 1});
}

bool dijkstra(int s, int t) {
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
    }
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push(make_pair(0, s));
    while (!que.empty()) {
        pair<int, int> tmp = que.top();
        que.pop();
        int v = tmp.second;
        if (dist[v] < tmp.first) {
            continue;
        }
        for (int i = 0; i < G[v].size(); i++) {
            Edge e = G[v][i];
            if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                prevv[e.to] = v;
                preve[e.to] = i;
                que.push(make_pair(dist[e.to], e.to));
            }
        }
    }
    return dist[t] != INF;
}

int min_cost_flow(int s, int t, int f) {
    int res = 0;
    for (int i = 0; i < V; i++) {
        h[i] = 0;
    }
    while (f > 0) {
        if (!dijkstra(s, t)) {
            return -1;
        }
        for (int i = 0; i < V; i++) {
            if (dist[i] != INF) {
                h[i] += dist[i];
            }
        }
        int d = f;
        for (int v = t; v != s; v = prevv[v]) {
            d = min(d, G[prevv[v]][preve[v]].cap);
        }
        f -= d;
        res += d * h[t];
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
        int s, t, c;
        cin >> s >> t >> c;
        add_edge(s, t, 1, c);
    }
    cout << min_cost_flow(0, V - 1, 10000) << endl;
    return 0;
}