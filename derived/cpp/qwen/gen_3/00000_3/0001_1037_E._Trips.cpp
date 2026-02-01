#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m, k;
vector<int> adj[N];
bool chosen[N];
int deg[N];
int max_ans;

void add(int u) {
    if (deg[u] >= k) {
        chosen[u] = true;
        for (auto v : adj[u]) {
            if (chosen[v]) continue;
            deg[v]++;
            if (deg[v] == k) {
                add(v);
            }
        }
    }
}

void remove(int u) {
    if (chosen[u]) {
        chosen[u] = false;
        max_ans--;
        for (auto v : adj[u]) {
            if (!chosen[v]) continue;
            if (deg[v] == k) {
                remove(v);
            }
            deg[v]--;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        add(x); add(y);
        int ans = 0;
        for(int j=0;j<n;j++) if(chosen[j]) ans++;
        cout << ans << "\n";
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    return 0;
}