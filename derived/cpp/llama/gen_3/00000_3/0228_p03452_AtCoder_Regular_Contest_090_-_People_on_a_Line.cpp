#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int MAX_N = 100005;

struct Query {
    int u, v, d;
};

bool solve(int n, int m, const vector<Query>& queries) {
    vector<vector<pair<int, int>>> g(n + 1);
    for (const auto& query : queries) {
        g[query.u].emplace_back(query.v, query.d);
        g[query.v].emplace_back(query.u, -query.d);
    }

    vector<long long> dis(n + 1, numeric_limits<long long>::max());
    for (int i = 1; i <= n; ++i) {
        dis[i] = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (const auto& e : g[u]) {
                int v = e.first;
                if (dis[v] > dis[u] + e.second) {
                    dis[v] = dis[u] + e.second;
                    q.push(v);
                }
            }
        }
        for (const auto& e : g[i]) {
            int v = e.first;
            if (dis[v] != dis[i] + e.second) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Query> queries(m);
    for (auto& query : queries) {
        cin >> query.u >> query.v >> query.d;
    }

    if (solve(n, m, queries)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}