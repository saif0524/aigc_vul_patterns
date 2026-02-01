#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N, M;
    cin >> N >> M;
    vector<vector<pll>> adj(N+1);
    for(ll i=0; i<M; ++i){
        ll L, R, C;
        cin >> L >> R >> C;
        adj[L].emplace_back(R, C);
        adj[R].emplace_back(L, C);
        for(ll j=L+1; j<R; ++j){
            adj[j].emplace_back(j-1, C);
            adj[j].emplace_back(j+1, C);
        }
    }
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    vector<ll> dist(N+1, LLONG_MAX);
    dist[1] = 0;
    pq.emplace(0, 1);
    while(!pq.empty()){
        ll d = pq.top().first;
        ll u = pq.top().second;
        pq.pop();
        if(d > dist[u]) continue;
        for(auto [v, c] : adj[u]){
            if(dist[v] > dist[u] + c){
                dist[v] = dist[u] + c;
                pq.emplace(dist[v], v);
            }
        }
    }
    if(dist[N] == LLONG_MAX) cout << -1;
    else cout << dist[N];
}