#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> cities(n);
    for(auto &city : cities) cin >> city;
    int r;
    cin >> r;
    vector<string> route(r);
    for(auto &city : route) cin >> city;
    vector<int> durations(r-1);
    for(auto &dur : durations) cin >> dur;
    int q;
    cin >> q;
    vector<string> qsrc(q), qdst(q);
    for(int i=0; i<q; ++i) cin >> qsrc[i] >> qdst[i];
    map<string, int> city_index;
    for(int i=0; i<n; ++i) city_index[cities[i]] = i;
    vector<vector<int>> dp(n, vector<int>(1<<n, INT_MAX));
    for(int i=0; i<r; ++i) dp[city_index[route[i]]][1<<city_index[route[i]]] = 0;
    for(int mask=1; mask<(1<<n); ++mask){
        for(int u=0; u<n; ++u){
            if(mask & (1<<u)){
                for(int i=0; i<r-1; ++i){
                    int v = city_index[route[i+1]];
                    int prev_mask = mask ^ (1<<u);
                    if(prev_mask & (1<<v)){
                        dp[u][mask] = min(dp[u][mask], dp[v][prev_mask] + durations[i]);
                    }
                }
            }
        }
    }
    for(int i=0; i<q; ++i){
        int src = city_index[qsrc[i]], dst = city_index[qdst[i]];
        int min_cost = INT_MAX, min_flights = INT_MAX;
        for(int k=0; k<n; ++k){
            if(dp[k][(1<<src)|(1<<dst)] != INT_MAX){
                int flights = bitset<32>((1<<src)|(1<<dst)).count() - 2;
                if(dp[k][(1<<src)|(1<<dst)] < min_cost || (dp[k][(1<<src)|(1<<dst)] == min_cost && flights < min_flights)){
                    min_cost = dp[k][(1<<src)|(1<<dst)];
                    min_flights = flights;
                }
            }
        }
        if(min_cost == INT_MAX) cout << "-1 -1 ";
        else cout << min_cost << " " << min_flights + 1 << " ";
    }
    cout << "\n";
}