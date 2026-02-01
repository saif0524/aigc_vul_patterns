#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAX_N = 100005;
const long long INF = LLONG_MAX;

vector<pair<int, int>> graph[MAX_N];
long long dist[MAX_N];

void dijkstra(int start) {
    for (int i = 1; i <= MAX_N; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (auto& edge : graph[u]) {
            int v = edge.first;
            long long w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    int S, T;
    cin >> S >> T;

    int U, V;
    cin >> U >> V;

    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;

        graph[A].emplace_back(B, C);
        graph[B].emplace_back(A, C);
    }

    dijkstra(S);
    vector<int> path;
    int current = T;
    while (current != S) {
        path.push_back(current);
        for (auto& edge : graph[current]) {
            if (dist[current] - edge.second == dist[edge.first]) {
                current = edge.first;
                break;
            }
        }
    }
    path.push_back(S);
    reverse(path.begin(), path.end());

    vector<bool> used(M + 1, false);
    for (int i = 0; i < path.size() - 1; i++) {
        for (auto& edge : graph[path[i]]) {
            if (edge.first == path[i + 1]) {
                for (int j = 0; j < M; j++) {
                    int A, B, C;
                    cin >> A >> B >> C;
                    if (A == path[i] && B == path[i + 1] || A == path[i + 1] && B == path[i]) {
                        used[j + 1] = true;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        graph[i].clear();
    }

    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        if (used[i + 1]) {
            graph[A].emplace_back(B, 0);
            graph[B].emplace_back(A, 0);
        } else {
            graph[A].emplace_back(B, C);
            graph[B].emplace_back(A, C);
        }
    }

    dijkstra(U);

    cout << dist[V] << endl;

    return 0;
}