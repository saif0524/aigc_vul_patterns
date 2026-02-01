#include <bits/stdc++.h>
using namespace std;

const int MAXV = 1005, MAXE = 2005, INF = 1e9;
int V, E, dist[MAXV], parent[MAXV], tape_used, flow;
vector<int> adj[MAXV];
pair<int, int> edges[MAXE];

struct Edge {
    int to, cap, rev;
};

vector<Edge> graph[MAXV];

void add_edge(int from, int to, int cap) {
    graph[from].push_back({to, cap, (int)graph[to].size()});
    graph[to].push_back({from, 0, (int)graph[from].size() - 1});
}

bool bfs(int s, int t) {
    fill(dist, dist + V, INF);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& e : graph[v]) {
            if (e.cap > 0 && dist[e.to] == INF) {
                dist[e.to] = dist[v] + 1;
                q.push(e.to);
            }
        }
    }
    return dist[t] != INF;
}

int dfs(int v, int t, int f) {
    if (v == t || f == 0) return f;
    for (int& i = parent[v]; i < graph[v].size(); ++i) {
        Edge& e = graph[v][i];
        if (e.cap > 0 && dist[v] + 1 == dist[e.to]) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                graph[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    int max_flow = 0;
    while (bfs(s, t)) {
        fill(parent, parent + V, 0);
        while (int d = dfs(s, t, INF)) {
            max_flow += d;
        }
    }
    return max_flow;
}

void min_cut(int s, int t) {
    queue<int> q;
    bool visited[MAXV] = {0};
    q.push(s);
    visited[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (Edge& e : graph[v]) {
            if (e.cap > 0 && !visited[e.to]) {
                visited[e.to] = true;
                q.push(e.to);
            }
        }
    }
    for (int e = 0; e < E; ++e) {
        int u = edges[e].first, v = edges[e].second, c = edges[e].second;
        if (visited[u] && !visited[v]) {
            tape_used += c;
            add_edge(u, v, 0);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> V >> E;
    for (int i = 0; i < E; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        edges[i] = {u, v};
        add_edge(u, v, c);
    }
    int max_flow_value = max_flow(0, V - 1);
    tape_used = 0;
    min_cut(0, V - 1);
    if (max_flow_value > 0 && tape_used <= 10000) {
        cout << tape_used << "\n";
    } else {
        cout << "-1\n";
    }
}