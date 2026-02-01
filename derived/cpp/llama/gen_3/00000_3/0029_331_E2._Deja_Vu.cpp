#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;

struct Edge {
    int to, visions;
    vector<int> visionList;
};

vector<Edge> adjList[100];
bool visited[100][100][100][100];
vector<int> path;

void dfs(int u, int v, int visionIndex, int depth) {
    if (depth > 2 * 50) return;
    if (visionIndex == adjList[u][v].visionList.size()) {
        if (u == adjList[u][v].to && depth > 0) {
            path.push_back(u);
            cout << path.size() << endl;
            for (int i = 0; i < path.size(); i++) cout << path[i] + 1 << " ";
            exit(0);
        }
        return;
    }
    if (visited[u][v][visionIndex][depth]) return;
    visited[u][v][visionIndex][depth] = true;
    path.push_back(u);
    dfs(adjList[u][v].visionList[visionIndex], adjList[u][v].visionList[visionIndex], 0, depth + 1);
    path.pop_back();
    dfs(adjList[u][v].to, adjList[u][v].to, visionIndex + 1, depth + 1);
}

int dp[100][100][100][100];

void dpDfs(int u, int v, int visionIndex, int depth) {
    if (depth > 2 * 50) return;
    if (visionIndex == adjList[u][v].visionList.size()) {
        if (u == adjList[u][v].to && depth > 0) {
            dp[u][v][visionIndex][depth] = 1;
        }
        return;
    }
    if (dp[u][v][visionIndex][depth] != 0) return;
    dpDfs(adjList[u][v].visionList[visionIndex], adjList[u][v].visionList[visionIndex], 0, depth + 1);
    dpDfs(adjList[u][v].to, adjList[u][v].to, visionIndex + 1, depth + 1);
    dp[u][v][visionIndex][depth] = (dp[adjList[u][v].visionList[visionIndex]][adjList[u][v].visionList[visionIndex]][0][depth + 1] + dp[adjList[u][v].to][adjList[u][v].to][visionIndex + 1][depth + 1]) % MOD;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to, visions;
        cin >> from >> to >> visions;
        from--; to--;
        vector<int> visionList;
        for (int j = 0; j < visions; j++) {
            int v;
            cin >> v;
            v--;
            visionList.push_back(v);
        }
        adjList[from].push_back({to, visions, visionList});
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < adjList[i].size(); j++) {
            dfs(i, j, 0, 0);
        }
    }
    cout << 0 << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < adjList[i].size(); j++) {
            dpDfs(i, j, 0, 0);
        }
    }
    for (int i = 1; i <= 2 * n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < adjList[j].size(); k++) {
                sum = (sum + dp[j][k][adjList[j][k].visions][i]) % MOD;
            }
        }
        cout << sum << endl;
    }
    return 0;
}