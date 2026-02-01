#include <iostream>
#include <vector>
#include <bitset>
#include <climits>

using namespace std;

const int MAX_N = 15;
const int MAX_M = MAX_N * (MAX_N - 1) / 2;

struct Edge {
    int a, b, c;
};

int N, M;
Edge edges[MAX_M];
int adj[MAX_N][MAX_N];

void buildAdjacencyMatrix() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            adj[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < M; i++) {
        adj[edges[i].a - 1][edges[i].b - 1] = edges[i].c;
        adj[edges[i].b - 1][edges[i].a - 1] = edges[i].c;
    }
}

int minBudget = INT_MAX;

void dfs(int curr, int prev, bitset<MAX_N> visited, int budget) {
    if (curr == N - 1) {
        minBudget = min(minBudget, budget);
        return;
    }
    for (int next = 0; next < N; next++) {
        if (next != prev && !visited[next] && adj[curr][next] != INT_MAX) {
            visited[next] = true;
            dfs(next, curr, visited, budget + adj[curr][next]);
            visited[next] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].c;
    }
    buildAdjacencyMatrix();
    bitset<MAX_N> visited;
    visited[0] = true;
    dfs(0, -1, visited, 0);
    int ans = minBudget;
    for (int i = 0; i < M; i++) {
        int a = edges[i].a - 1;
        int b = edges[i].b - 1;
        adj[a][b] = INT_MAX;
        adj[b][a] = INT_MAX;
        minBudget = INT_MAX;
        visited.reset();
        visited[0] = true;
        dfs(0, -1, visited, 0);
        ans = min(ans, minBudget + edges[i].c);
        adj[a][b] = edges[i].c;
        adj[b][a] = edges[i].c;
    }
    cout << ans << endl;
    return 0;
}