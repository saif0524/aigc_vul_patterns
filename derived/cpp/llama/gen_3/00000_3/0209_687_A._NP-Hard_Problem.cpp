#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 100005;

vector<int> graph[MAX_N];
int color[MAX_N];

void bfs(int start, int c) {
    queue<int> q;
    q.push(start);
    color[start] = c;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (color[v] == 0) {
                color[v] = 3 - color[u];
                q.push(v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool bipartite = true;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            bfs(i, 1);
        }
        for (int j : graph[i]) {
            if (color[i] == color[j]) {
                bipartite = false;
                break;
            }
        }
        if (!bipartite) break;
    }

    if (bipartite) {
        vector<int> set1, set2;
        int count1 = 0, count2 = 0;
        for (int i = 1; i <= n; i++) {
            if (color[i] == 1) {
                count1++;
            } else if (color[i] == 2) {
                count2++;
            }
        }
        cout << count1 << '\n';
        for (int i = 1; i <= n; i++) {
            if (color[i] == 1) {
                cout << i << ' ';
            }
        }
        cout << '\n' << count2 << '\n';
        for (int i = 1; i <= n; i++) {
            if (color[i] == 2) {
                cout << i << ' ';
            }
        }
    } else {
        cout << -1;
    }

    return 0;
}