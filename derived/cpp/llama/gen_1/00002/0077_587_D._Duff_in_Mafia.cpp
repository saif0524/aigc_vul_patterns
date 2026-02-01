#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

const int MAX_N = 50005;
const long long INF = 1e18;

struct Edge {
    int u, v, c, t, id;
};

vector<Edge> edges;
vector<vector<pair<int, int>>> g(MAX_N);
vector<int> match(MAX_N, -1);
vector<long long> dist(MAX_N, INF);
vector<bool> used(MAX_N, false);

bool bfs() {
    queue<int> q;
    for (int i = 0; i < MAX_N; i++) {
        if (!used[i] && match[i] == -1) {
            dist[i] = 0;
            q.push(i);
        } else {
            dist[i] = INF;
        }
    }
    dist[MAX_N - 1] = INF;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == MAX_N - 1) {
            return true;
        }
        for (auto e : g[u]) {
            int v = e.first;
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return false;
}

bool dfs(int u) {
    if (u == MAX_N - 1) {
        return true;
    }
    for (auto e : g[u]) {
        int v = e.first;
        if (dist[v] == dist[u] + 1) {
            if (dfs(v)) {
                match[u] = e.second;
                match[v] = u;
                used[u] = used[v] = true;
                return true;
            }
        }
    }
    dist[u] = INF;
    return false;
}

void hopcroftKarp() {
    int cnt = 0;
    while (bfs()) {
        for (int i = 0; i < MAX_N; i++) {
            if (!used[i] && match[i] == -1 && dfs(i)) {
                cnt++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    edges.resize(m);
    for (auto& e : edges) {
        cin >> e.v >> e.u >> e.c >> e.t;
        e.id = &e - &edges[0];
    }

    for (auto& e : edges) {
        g[e.v].emplace_back(e.u, e.id);
        g[e.u].emplace_back(e.v, e.id);
    }

    hopcroftKarp();

    long long max_t = 0;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (match[i] != -1) {
            auto e = edges[match[i]];
            if (e.t > max_t) {
                max_t = e.t;
            }
            ans.push_back(e.id + 1);
        }
    }

    if (max_t == 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        cout << max_t << " " << ans.size() << endl;
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}