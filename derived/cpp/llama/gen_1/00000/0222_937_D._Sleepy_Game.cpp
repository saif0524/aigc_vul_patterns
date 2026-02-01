#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
vector<int> G[MAXN];
int s;
bool vis[MAXN];
int deg[MAXN];
bool can_win[MAXN];
int parent[MAXN];

void dfs(int u) {
    vis[u] = true;
    for (int v : G[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        deg[i] = c;
        for (int j = 0; j < c; j++) {
            int x;
            cin >> x;
            G[i].push_back(x);
        }
    }
    cin >> s;
    vector<int> seq;
    seq.push_back(s);
    while (true) {
        bool found = false;
        for (int v : G[seq.back()]) {
            if (deg[v] > 0) {
                found = true;
                seq.push_back(v);
                deg[seq[seq.size() - 2]]--;
                break;
            }
        }
        if (!found) break;
        found = false;
        for (int v : G[seq.back()]) {
            if (deg[v] > 0) {
                found = true;
                seq.push_back(v);
                deg[seq[seq.size() - 2]]--;
                break;
            }
        }
        if (!found) break;
    }
    if (seq.size() > 1) {
        cout << "Win\n";
        for (int x : seq) cout << x << " ";
        cout << "\n";
        return;
    }
    fill(vis, vis + n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && deg[i] > 0) {
            dfs(i);
        }
    }
    if (vis[s] && !vis[0]) {
        cout << "Draw\n";
        return;
    }
    cout << "Lose\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}