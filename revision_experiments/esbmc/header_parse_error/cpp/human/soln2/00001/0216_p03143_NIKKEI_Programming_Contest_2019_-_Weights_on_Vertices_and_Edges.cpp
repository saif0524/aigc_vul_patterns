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
#define all(v) v.begin(), v.end()
#define pii pair <int , int>
#define F first
#define S second
const int N = 1e5 + 5;
int par[N];
long long S[N];
bool mark[N], isval[N];
vector <pii> g[N];
vector < pair <int , pii> > edge;

void dfs(int v, int w) {
    mark[v] = 1;
    for (pii e : g[v]) {
        if (e.S > w) return ;
        if (!mark[e.F]) dfs(e.F, w);
    }
}

int getpar(int v) {return par[v] = (par[v] == v ? v : getpar(par[v]));}
bool Union(int u, int v, int w) {
    u = getpar(u), v = getpar(v);
    if (u == v) return S[u] >= w;
    par[v] = u, S[u] += S[v];
    return S[u] >= w;
}

int main()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> S[i], par[i] = i;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        edge.push_back({w, {u, v}});
    }
    sort(all(edge));
    for (int i = 0; i < m; i++) {
        int w = edge[i].F, u = edge[i].S.F, v = edge[i].S.S;
        g[u].push_back({v, w}), g[v].push_back({u, w});
        isval[i] = Union(u, v, w);
    }
    reverse(all(edge));
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int w = edge[i].F, u = edge[i].S.F, v = edge[i].S.S;
        if (mark[u]) continue ;
        if (isval[m-i-1]) dfs(u, w);
        else ans++;
    }
    cout << ans << "\n";

    return 0;
}