#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int dp[MAXN], in_degree[MAXN];

void solve() {
    int n, m, s;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            adj[i].push_back(x);
            in_degree[x]++;
        }
    }
    cin >> s;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (--in_degree[v] == 0) q.push(v);
            if (dp[v] == -1) dp[u] = 1;
            else if (dp[v] == 1) dp[u] = -1;
        }
    }
    if (dp[s] == -1) {
        cout << "Win\n";
        vector<int> path;
        path.push_back(s);
        while (true) {
            bool found = false;
            for (int v : adj[s]) {
                if (dp[v] == 1) {
                    s = v;
                    path.push_back(s);
                    found = true;
                    break;
                }
            }
            if (!found) break;
        }
        for (int u : path) cout << u << " ";
        cout << endl;
    } else if (dp[s] == 0) {
        cout << "Draw\n";
    } else {
        cout << "Lose\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < MAXN; i++) {
        dp[i] = -1;
        in_degree[i] = 0;
    }
    solve();
    return 0;
}