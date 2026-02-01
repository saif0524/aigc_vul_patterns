#include <iostream>
#include <vector>
#include <queue>
#include <limits>

const int INF = std::numeric_limits<int>::max();

int main() {
    int n, m, k, c, d;
    std::cin >> n >> m >> k >> c >> d;

    std::vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> a[i];
    }

    std::vector<std::vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        --x; --y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    std::vector<int> dis(n, INF);
    dis[0] = 0;

    std::vector<std::vector<int>> paths(n);
    std::queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (dis[neighbor] > dis[node] + 1) {
                dis[neighbor] = dis[node] + 1;
                paths[neighbor].clear();
                paths[neighbor].push_back(node);
                q.push(neighbor);
            } else if (dis[neighbor] == dis[node] + 1) {
                paths[neighbor].push_back(node);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < k; ++i) {
        int node = a[i] - 1;
        int dist = dis[node];
        ans += c * dist;
        while (node != 0) {
            for (int j = i + 1; j < k; ++j) {
                if (a[j] - 1 == node && dis[node] == dis[a[j] - 1]) {
                    ++ans;
                }
            }
            node = paths[node][0];
        }
    }

    std::cout << ans << std::endl;
    return 0;
}