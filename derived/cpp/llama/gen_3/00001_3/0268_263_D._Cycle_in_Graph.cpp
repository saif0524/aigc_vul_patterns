#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

const int MAX_N = 100005;

vector<int> adj[MAX_N];
bool visited[MAX_N];
int parent[MAX_N];

void bfs(int start, int end) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = node;
                q.push(neighbor);
                if (neighbor == end) {
                    return;
                }
            }
        }
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (adj[i].size() >= k) {
            for (int j = 0; j < adj[i].size(); j++) {
                int neighbor = adj[i][j];
                if (adj[neighbor].size() >= k) {
                    for (int l = 0; l < adj[neighbor].size(); l++) {
                        int commonNeighbor = adj[neighbor][l];
                        if (commonNeighbor!= i && adj[commonNeighbor].size() >= k) {
                            vector<int> path;
                            path.push_back(i);
                            path.push_back(neighbor);
                            path.push_back(commonNeighbor);
                            for (int node : adj[commonNeighbor]) {
                                if (node!= neighbor && node!= i && adj[node].size() >= k) {
                                    path.push_back(node);
                                    cout << path.size() << endl;
                                    for (int x : path) {
                                        cout << x << " ";
                                    }
                                    cout << endl;
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
    bfs(1, -1);
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() >= k) {
            for (int j = 0; j < adj[i].size(); j++) {
                int neighbor = adj[i][j];
                if (adj[neighbor].size() >= k) {
                    for (int l = 0; l < adj[neighbor].size(); l++) {
                        int commonNeighbor = adj[neighbor][l];
                        if (commonNeighbor!= i) {
                            vector<int> path;
                            path.push_back(i);
                            path.push_back(neighbor);
                            path.push_back(commonNeighbor);
                            int currentNode = commonNeighbor;
                            while (parent[currentNode]!= i) {
                                path.push_back(parent[currentNode]);
                                currentNode = parent[currentNode];
                            }
                            cout << path.size() << endl;
                            for (int x : path) {
                                cout << x << " ";
                            }
                            cout << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }

    return 0;
}