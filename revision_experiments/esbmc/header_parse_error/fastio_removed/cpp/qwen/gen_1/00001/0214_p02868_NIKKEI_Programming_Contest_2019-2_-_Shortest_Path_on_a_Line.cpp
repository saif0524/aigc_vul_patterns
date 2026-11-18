// [esbmc] replaced #include <bits/stdc++.h> with ESBMC-compatible headers
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <istream>
#include <ostream>
#include <ios>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <streambuf>
#include <string>
#include <string_view>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <iterator>
#include <memory>
#include <tuple>
#include <limits>
#include <random>
#include <complex>
#include <valarray>
#include <stdexcept>
#include <exception>
#include <typeinfo>
#include <type_traits>
#include <initializer_list>
#include <numbers>
#include <any>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main(){
    ((void)0);
    ((void)0);
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