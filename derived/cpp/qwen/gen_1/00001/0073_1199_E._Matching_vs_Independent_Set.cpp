#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int v = 3 * n;
    vector<vector<int>> adj(v + 1);
    vector<int> edges;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back(u);
        edges.push_back(v);
    }

    vector<int> match(v + 1, -1);
    vector<bool> visited(v + 1, false);

    function<bool(int)> augment = [&](int u) -> bool {
        if(visited[u]) return false;
        visited[u] = true;
        for(int v : adj[u]) {
            if(match[v] == -1 || augment(match[v])) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    };

    int matching_size = 0;
    for(int i = 1; i <= v; i++) {
        if(match[i] == -1) {
            fill(visited.begin(), visited.end(), false);
            if(augment(i)) {
                matching_size++;
            }
        }
    }

    if(matching_size == n) {
        cout << "Matching\n";
        vector<int> ans;
        for(int i = 0; i < m; i++) {
            int u = edges[2 * i], v = edges[2 * i + 1];
            if(match[u] == v) {
                ans.push_back(i + 1);
            }
        }
        for(int x : ans) cout << x << " ";
        cout << "\n";
        return;
    }

    vector<int> indSet;
    for(int i = 1; i <= v; i++) {
        if(!visited[i]) {
            indSet.push_back(i);
            if(indSet.size() == n) break;
            queue<int> q;
            q.push(i);
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for(int v : adj[u]) {
                    if(!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }

    if(indSet.size() == n) {
        cout << "IndSet\n";
        for(int x : indSet) cout << x << " ";
        cout << "\n";
        return;
    }

    cout << "Impossible\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}