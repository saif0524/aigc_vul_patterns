#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <cmath>
#include <bitset>

using namespace std;

const int MAX_N = 110;
const int MAX_M = 10;
const int INF = numeric_limits<int>::max();

struct Edge {
    int to, weight;
};

vector<Edge> graph[MAX_N];

int distance[MAX_N][MAX_N];

void floydWarshall(int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }
}

void solve() {
    int m, n, k, d;
    cin >> m >> n >> k >> d;

    if (m == 0 && n == 0 && k == 0 && d == 0) return;

    vector<int> cakes(m);
    for (int i = 0; i < m; ++i) cin >> cakes[i];

    for (int i = 0; i < m + n + 2; ++i) {
        graph[i].clear();
        for (int j = 0; j < m + n + 2; ++j) {
            distance[i][j] = INF;
        }
        distance[i][i] = 0;
    }

    for (int i = 0; i < d; ++i) {
        string s, t;
        int e;
        cin >> s >> t >> e;

        int u, v;
        if (s[0] == 'H') u = 0;
        else if (s[0] == 'D') u = m + n + 1;
        else if (s[0] == 'C') u = stoi(s.substr(1)) + 1;
        else u = stoi(s.substr(1)) + m + 1;

        if (t[0] == 'H') v = 0;
        else if (t[0] == 'D') v = m + n + 1;
        else if (t[0] == 'C') v = stoi(t.substr(1)) + 1;
        else v = stoi(t.substr(1)) + m + 1;

        graph[u].push_back({v, e});
        graph[v].push_back({u, e});
    }

    floydWarshall(m + n + 2);

    int ans = numeric_limits<int>::max();
    for (int mask = 0; mask < (1 << m); ++mask) {
        int total = 0;
        int curr = 0;

        for (int i = 0; i < m; ++i) {
            if ((mask & (1 << i)) != 0) {
                total += cakes[i];
                if (i == 0) curr = 1;
                else curr = i + 1;
            }
        }

        int dist = distance[0][curr];
        if (dist != INF) {
            total -= dist * k;
        }

        dist = distance[curr][m + n + 1];
        if (dist != INF) {
            total -= dist * k;
        }

        ans = min(ans, total);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        solve();
    }

    return 0;
}