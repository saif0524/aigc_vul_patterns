#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge {
    int to;
};

int n, m;
vector<vector<edge>> adj;
vector<int> indeg;
vector<ll> h;

void solve() {
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }
    vector<ll> reachable(n, 0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        reachable[u] = 1;
        for (edge &e : adj[u]) {
            int v = e.to;
            reachable[v] |= reachable[u];
            if (--indeg[v] == 0) {
                q.push(v);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (indeg[i] == 0 && reachable[i]) {
            cout << "WIN\n";
            vector<ll> h_new(n, 0);
            h_new[i] = h[i];
            queue<int> q2;
            q2.push(i);
            vector<bool> visited(n, false);
            visited[i] = true;
            while (!q2.empty()) {
                int u = q2.front();
                q2.pop();
                for (edge &e : adj[u]) {
                    int v = e.to;
                    if (reachable[v]) {
                        h_new[v] = h[u];
                        if (!visited[v]) {
                            visited[v] = true;
                            q2.push(v);
                        }
                    }
                }
            }
            for (int j = 0; j < n; ++j) {
                if (!reachable[j]) {
                    h_new[j] = h[j];
                }
            }
            for (int j = 0; j < n; ++j) {
                cout << h_new[j] << " ";
            }
            cout << "\n";
            return;
        }
    }
    cout << "LOSE\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    adj.resize(n);
    indeg.assign(n, 0);
    h.resize(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back({v});
        indeg[v]++;
    }
    solve();
}