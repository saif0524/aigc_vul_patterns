#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    adj.resize(n + 1);
    vector<pair<int, int>> edges;
    for (int i = 0; i < n - 1; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        adj[ai].push_back(bi);
        adj[bi].push_back(ai);
        edges.push_back({ai, bi});
    }

    visited.resize(n + 1);
    bfs(1);

    int count = 0;
    vector<pair<pair<int, int>, pair<int, int>>> plan;
    for (int i = 2; i <= n; ++i) {
        if (!visited[i]) {
            for (auto& edge : edges) {
                if (!visited[edge.first] && !visited[edge.second]) {
                    plan.push_back({edge, {1, i}});
                    visited[edge.first] = visited[edge.second] = true;
                    ++count;
                    break;
                }
            }
        }
    }

    cout << count << "\n";
    for (auto& action : plan) {
        cout << action.first.first << " " << action.first.second << " " << action.second.first << " " << action.second.second << "\n";
    }

    return 0;
}