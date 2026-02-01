#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1005;
const ll INF = 1e18;

vector<pair<int, ll>> adj[MAXN];
vector<tuple<int, int, ll>> edges;
int n, m, s, t;
ll L;

bool spfa(ll mid) {
    vector<ll> dist(n, INF);
    vector<int> cnt(n, 0);
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &e : adj[u]) {
            int v = e.first;
            ll w = e.second;
            if (w == 0) w = mid;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n) return false;
                q.push(v);
            }
        }
    }
    return dist[t] <= L;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> L >> s >> t;
    for(int i = 0; i < m; ++i){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    ll lo = 1, hi = 1e18, ans = -1;
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        if(spfa(mid)){
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    if(ans == -1){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for(auto &[u, v, w] : edges){
        if(w == 0) w = ans;
        cout << u << " " << v << " " << w << "\n";
    }
}