#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<vector<int>> reverseGraph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        reverseGraph[v].push_back(u);
    }

    vector<int> topSort;
    vector<int> inDegree(n, 0);
    for (int i = 0; i < n; i++) {
        for (auto j : graph[i]) {
            inDegree[j]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topSort.push_back(node);
        for (auto neighbor : graph[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (topSort.size() != n) {
        cout << -1 << endl;
        return;
    }

    vector<unordered_map<int, int>> memo(n);
    vector<unordered_set<int>> visited(n);
    vector<bool> interesting(n, true);

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (dfs(graph, i, j, memo, visited, topSort)) count++;
            else interesting[i] = false;
        }
        if (count != n - 1) interesting[i] = false;
    }

    int cnt = 0;
    for (bool b : interesting) cnt += b;
    if (cnt < 0.2 * n) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < n; i++) {
            if (interesting[i]) cout << i + 1 << " ";
        }
        cout << endl;
    }
}

bool dfs(const vector<vector<int>>& graph, int source, int target, vector<unordered_map<int, int>>& memo, vector<unordered_set<int>>& visited, const vector<int>& topSort) {
    if (source == target) return true;
    if (memo[source].count(target)) return memo[source][target];
    for (auto neighbor : graph[source]) {
        if (neighbor == target) return memo[source][target] = 1;
        if (visited[neighbor].count(source)) continue;
        visited[neighbor].insert(source);
        bool found = dfs(graph, neighbor, target, memo, visited, topSort);
        visited[neighbor].erase(source);
        if (found) return memo[source][target] = 1;
    }
    return memo[source][target] = 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}