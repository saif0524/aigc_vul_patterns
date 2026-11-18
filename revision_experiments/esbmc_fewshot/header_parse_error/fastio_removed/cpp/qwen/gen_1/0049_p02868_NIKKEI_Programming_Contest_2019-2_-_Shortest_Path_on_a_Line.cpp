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
const int MAXN = 1e5 + 5;
const ll INF = 1e18;

struct Edge {
    int to;
    ll weight;
};

vector<Edge> adj[MAXN];
ll dist[MAXN];

void dijkstra(int start, int n) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    for (int i = 1; i <= n; ++i) dist[i] = INF;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.to;
            ll weight = edge.weight;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main(){
    ((void)0);
    ((void)0);
    
    int N, M;
    cin >> N >> M;
    
    for(int i=0; i<M; ++i){
        int L, R;
        ll C;
        cin >> L >> R >> C;
        for(int j=L; j<R; ++j){
            adj[j].push_back({j+1, C});
            adj[j+1].push_back({j, C});
        }
    }
    
    dijkstra(1, N);
    
    if(dist[N] == INF) cout << "-1\n";
    else cout << dist[N] << "\n";
    
    return 0;
}