#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 100;
const int MAX_M = 100;

vector<vector<pair<int, int>>> adjList(MAX_N);
bool visited[MAX_N];
set<int> colors;

void dfs(int u, int color) {
    visited[u] = true;
    for (const auto& edge : adjList[u]) {
        if (!visited[edge.first] && edge.second == color) {
            dfs(edge.first, color);
        }
    }
}

void findConnectedComponents(int u, int v) {
    colors.clear();
    for (int i = 0; i < MAX_N; ++i) {
        visited[i] = false;
    }
    for (const auto& edge : adjList[u]) {
        if (!visited[edge.first]) {
            dfs(edge.first, edge.second);
            colors.insert(edge.second);
        }
    }
    for (int i = 0; i < MAX_N; ++i) {
        visited[i] = false;
    }
    for (const auto& edge : adjList[v]) {
        if (!visited[edge.first]) {
            dfs(edge.first, edge.second);
            colors.insert(edge.second);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, color;
        cin >> u >> v >> color;
        --u;
        --v;
        --color;
        adjList[u].emplace_back(v, color);
        adjList[v].emplace_back(u, color);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        findConnectedComponents(u, v);
        cout << colors.size() << endl;
    }
    return 0;
}