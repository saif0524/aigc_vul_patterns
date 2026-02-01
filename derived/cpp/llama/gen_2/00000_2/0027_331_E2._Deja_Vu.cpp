#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

struct Edge {
    int to, len;
    vector<int> vision;
};

vector<Edge> graph[100];
int n, m;
bool found = false;

void printPath(int s, int t, const vector<int>& parent) {
    vector<int> path;
    int current = t;
    while (current != s) {
        path.push_back(current);
        current = parent[current];
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i] + 1 << " ";
    }
    cout << endl;
    found = true;
}

void bfs(int s) {
    queue<int> q;
    q.push(s);
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);
    visited[s] = true;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (const auto& edge : graph[current]) {
            int to = edge.to;
            if (!visited[to]) {
                visited[to] = true;
                parent[to] = current;
                q.push(to);
                vector<int> visionPath = {current};
                int p = current;
                for (int v : edge.vision) {
                    visionPath.push_back(v - 1);
                    if (p == v - 1) {
                        if (visionPath.size() <= 2 * n) {
                            printPath(s, to, parent);
                        }
                    }
                    p = v - 1;
                }
            } else if (parent[current] != -1 && parent[to] != -1) {
                int p = current;
                vector<int> visionPath = {current};
                for (int v : edge.vision) {
                    visionPath.push_back(v - 1);
                    if (p == v - 1) {
                        if (visionPath.size() <= 2 * n) {
                            printPath(s, to, parent);
                        }
                    }
                    p = v - 1;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int from, to, len;
        cin >> from >> to >> len;
        --from, --to;
        vector<int> vision(len);
        for (int j = 0; j < len; ++j) {
            cin >> vision[j];
        }
        graph[from].push_back({to, len, vision});
    }
    for (int i = 0; i < n && !found; ++i) {
        bfs(i);
    }
    if (!found) {
        cout << "0" << endl;
    }
    return 0;
}