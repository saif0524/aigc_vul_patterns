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

const int MAXN = 100005;
const ll INF = 1e18;

struct Edge {
    int to, id;
    ll cost;
};

vector<Edge> G[MAXN];
int N, M, S, T, U, V;

ll dijkstra(int start, int end) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vector<ll> dist(N + 1, INF);
    dist[start] = 0LL;
    pq.push({0LL, start});
    while (!pq.empty()) {
        pair<ll, int> p = pq.top();
        pq.pop();
        int u = p.second;
        ll d = p.first;
        if (dist[u] < d) continue;
        for (auto &e : G[u]) {
            if (dist[e.to] > d + e.cost) {
                dist[e.to] = d + e.cost;
                pq.push({dist[e.to], e.to});
            }
        }
    }
    return dist[end];
}

int main(){
    cin >> N >> M >> S >> T >> U >> V;
    for(int i = 0; i < M; i++){
        int A, B;
        ll C;
        cin >> A >> B >> C;
        G[A].push_back({B, i, C});
        G[B].push_back({A, i, C});
    }
    vector<ll> distS = dijkstra(S, N);
    vector<ll> distT = dijkstra(T, N);
    vector<ll> distU = dijkstra(U, N);
    vector<ll> distV = dijkstra(V, N);
    ll res = INF;
    for(int i = 0; i < M; i++){
        ll alt = distU[S] + distT[V] - distS[T];
        res = min(res, alt);
        alt = distV[S] + distT[U] - distS[T];
        res = min(res, alt);
        alt = distS[U] + distT[V] - distU[T];
        res = min(res, alt);
        alt = distS[V] + distT[U] - distU[T];
        res = min(res, alt);
    }
    res = min(res, distU[V]);
    cout << res;
}