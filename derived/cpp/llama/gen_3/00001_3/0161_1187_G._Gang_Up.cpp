#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX / 2;

struct Edge {
    int to, weight;
};

int main() {
    int n, m, k, c, d;
    cin >> n >> m >> k >> c >> d;

    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        graph[x].push_back({y, 1});
        graph[y].push_back({x, 1});
    }

    vector<vector<int>> dist(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (const auto& e : graph[v]) {
                if (dist[i][e.to] > dist[i][v] + e.weight) {
                    dist[i][e.to] = dist[i][v] + e.weight;
                    q.push(e.to);
                }
            }
        }
    }

    int ans = 0;
    sort(a.begin(), a.end(), [&](int x, int y) {
        return dist[x - 1][0] < dist[y - 1][0];
    });

    int cnt = 0;
    for (int i = 0; i < k; i++) {
        ans += c * (dist[a[i] - 1][0] + cnt);
        ans += d * cnt * cnt;
        cnt++;
    }

    cout << ans << endl;

    return 0;
}