#include <bits/stdc++.h>

using namespace std;

const long double EPS = 1e-9;

struct Edge {
    int to;
    int index;
    Edge(int to, int index) : to(to), index(index) {}
};

vector<vector<Edge>> graph;

void dfs(int v, int p, vector<long double>& p_fall, vector<long double>& ans) {
    for (const auto& edge : graph[v]) {
        if (edge.to == p) continue;
        dfs(edge.to, v, p_fall, ans);
        ans[v] += (1 - p_fall[v]) * ans[edge.to] * p_fall[edge.to];
        ans[v] += (1 - p_fall[v]) * (1 - p_fall[edge.to]);
    }
}

int main() {
    int N;
    cin >> N;

    vector<long double> p_fall(N);
    for (int i = 0; i < N; ++i) {
        cin >> p_fall[i];
    }

    graph = vector<vector<Edge>>(N);
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(Edge(v, i));
        graph[v].push_back(Edge(u, i));
    }

    int Q;
    cin >> Q;

    vector<long double> p_fall_new = p_fall;
    while (Q-- > 0) {
        int v;
        long double p;
        cin >> v >> p;

        p_fall_new[v] = p;

        vector<long double> ans(N, 0);
        for (int i = 0; i < N; ++i) {
            dfs(i, -1, p_fall_new, ans);
        }

        long double sum = 0;
        for (int i = 0; i < N; ++i) {
            sum += p_fall_new[i] * (1 + ans[i]);
        }

        cout << fixed << setprecision(5) << sum << endl;

        p_fall = p_fall_new;
    }
}