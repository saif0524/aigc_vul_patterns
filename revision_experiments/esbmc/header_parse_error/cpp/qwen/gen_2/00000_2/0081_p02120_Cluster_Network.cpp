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

struct DSU {
    vector<int> p, sz, perf;
    DSU(int n) : p(n), sz(n, 1), perf(n, 0) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int u) {
        return u == p[u] ? u : p[u] = find(p[u]);
    }
    void unite(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return;
        if (sz[u] < sz[v]) swap(u, v);
        p[v] = u;
        sz[u] += sz[v];
        perf[u] += perf[v];
    }
    int getPerformance(int u) {
        return perf[find(u)];
    }
    void setPerformance(int u, int w) {
        perf[u] = w;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    DSU dsu(N);
    vector<int> weights(N);
    for(int i=0;i<N;i++){
        cin >> weights[i];
        dsu.setPerformance(i, weights[i]);
    }
    vector<tuple<int, int, int>> edges(M);
    for(int i=0;i<M;i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[i] = make_tuple(min(u,v), max(u,v), i);
    }
    sort(edges.begin(), edges.end());
    vector<int> node_order(N);
    for(int i=0;i<N;i++){
        cin >> node_order[i];
        node_order[i]--;
    }
    reverse(node_order.begin(), node_order.end());
    vector<bool> removed(N, false);
    vector<int> answer(N);
    int last = 0;
    for(int i=0;i<N;i++){
        int u = node_order[i];
        removed[u] = true;
        for(auto &[v1, v2, idx] : edges){
            if(idx < last) continue;
            if(removed[v1] && removed[v2]){
                dsu.unite(v1, v2);
            }
            else if(removed[v1] || removed[v2]){
                break;
            }
            else{
                last = idx;
                break;
            }
        }
        int best = 0;
        for(int v = 0; v < N; v++){
            if(!removed[v]){
                best = max(best, dsu.getPerformance(v));
            }
        }
        answer[N-i-1] = best;
    }
    for(auto x : answer){
        cout << x << "\n";
    }
}