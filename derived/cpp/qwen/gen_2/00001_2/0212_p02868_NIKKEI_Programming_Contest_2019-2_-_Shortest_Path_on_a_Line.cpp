#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll inf = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<ll> min_cost(N+1, inf);
    min_cost[1] = 0;
    vector<vector<pll>> diff(N+1);
    for(int i=0;i<M;i++){
        int L, R;
        ll C;
        cin >> L >> R >> C;
        diff[L].push_back({R, C});
    }
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        ll current_cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(current_cost > min_cost[u]) continue;
        for(auto [v, additional_cost] : diff[u]){
            ll new_cost = current_cost + additional_cost;
            if(new_cost < min_cost[v]){
                min_cost[v] = new_cost;
                pq.push({new_cost, v});
            }
        }
    }
    if(min_cost[N] == inf) cout << -1 << "\n";
    else cout << min_cost[N] << "\n";
}