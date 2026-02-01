#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int MAX_N = 100;
const int INF = 1e9;

int N, M;
vector<pair<int, int>> E[MAX_N];
int dist[MAX_N][MAX_N];

void bfs(int s) {
    queue<int> que;
    que.push(s);
    fill(dist[s], dist[s] + N, INF);
    dist[s][s] = 0;

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (auto e : E[v]) {
            int to = e.first;
            int cost = e.second;

            if (dist[s][v] + cost < dist[s][to]) {
                dist[s][to] = dist[s][v] + cost;
                que.push(to);
            }
        }
    }
}

bool used[MAX_N][MAX_N];

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;

        E[a].emplace_back(b, c);
        E[b].emplace_back(a, c);
    }

    for (int i = 0; i < N; i++) {
        bfs(i);

        for (int j = 0; j < N; j++) {
            for (auto e : E[j]) {
                int to = e.first;
                int cost = e.second;

                if (dist[i][j] + cost == dist[i][to]) {
                    used[i][to] = used[to][i] = true;
                }
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (auto e : E[i]) {
            int to = e.first;

            if (!used[i][to]) {
                ans++;
            }
        }
    }

    cout << ans / 2 << endl;

    return 0;
}