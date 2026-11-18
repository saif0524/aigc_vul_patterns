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

struct Edge {
    int u, v;
    ll w;
};

struct DSU {
    vector<int> par;
    vector<ll> sum;
    DSU(int n) : par(n + 1), sum(n + 1, 0) {
        for(int i = 1; i <= n; ++i) par[i] = i;
    }
    int find(int x) {
        return (par[x] == x ? x : par[x] = find(par[x]));
    }
    void unite(int a, int b, ll val) {
        int ra = find(a), rb = find(b);
        if ra != rb) {
            par[rb] = ra;
            sum[ra] += sum[rb] + val;
        } else {
            sum[ra] += val;
        }
    }
    bool same(int a, int b) {
        return find(a) == find(b);
    }
    ll getSum(int a) {
        return sum[find(a)];
    }
};

bool cmp(const Edge &a, const Edge &b) {
    return a.w > b.w;
}

int main(){
    ((void)0);
    ((void)0);
    int N, M;
    cin >> N >> M;
    vector<ll> X(N+1);
    for(int i = 1; i <= N; ++i) cin >> X[i];
    vector<Edge> edges(M);
    for(int i = 0; i < M; ++i) cin >> edges[i].u >> edges[i].v >> edges[i].w;
    
    DSU dsu(N);
    for(int i = 1; i <= N; ++i) dsu.sum[i] = X[i];
    
    sort(edges.begin(), edges.end(), cmp);
    
    int ans = 0;
    for(auto &e : edges){
        int u = e.u, v = e.v;
        ll w = e.w;
        if(dsu.getSum(u) >= w && dsu.getSum(v) >= w){
            dsu.unite(u, v, w);
        } else {
            ++ans;
        }
    }
    
    cout << ans;
}