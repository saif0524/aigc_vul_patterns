#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    int S, T;
    cin >> S >> T;
    int U, V;
    cin >> U >> V;
    vector<vector<pair<int, ll>>> adj(N+1);
    vector<vector<pair<int, ll>>> rev_adj(N+1);
    for(int i = 0; i < M; i++){
        int A, B;
        ll C;
        cin >> A >> B >> C;
        adj[A].emplace_back(B, C);
        rev_adj[B].emplace_back(A, C);
    }
    vector<ll> dist_from_S(N+1, LLONG_MAX);
    vector<ll> dist_from_T(N+1, LLONG_MAX);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist_from_S[S] = 0;
    pq.emplace(0, S);
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if(d > dist_from_S[u]) continue;
        for(auto [v, c] : adj[u]){
            if(dist_from_S[v] > dist_from_S[u] + c){
                dist_from_S[v] = dist_from_S[u] + c;
                pq.emplace(dist_from_S[v], v);
            }
        }
    }
    dist_from_T[T] = 0;
    pq.emplace(0, T);
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if(d > dist_from_T[u]) continue;
        for(auto [v, c] : rev_adj[u]){
            if(dist_from_T[v] > dist_from_T[u] + c){
                dist_from_T[v] = dist_from_T[u] + c;
                pq.emplace(dist_from_T[v], v);
            }
        }
    }
    ll min_cost = LLONG_MAX;
    for(int i = 1; i <= N; i++){
        for(auto [j, c] : adj[i]){
            ll cost = dist_from_S[i] + dist_from_T[j];
            min_cost = min(min_cost, cost);
        }
    }
    ll direct_cost = dist_from_S[U] + dist_from_T[V];
    min_cost = min(min_cost, direct_cost);
    direct_cost = dist_from_S[V] + dist_from_T[U];
    min_cost = min(min_cost, direct_cost);
    cout << min_cost << "\n";
    return 0;
}