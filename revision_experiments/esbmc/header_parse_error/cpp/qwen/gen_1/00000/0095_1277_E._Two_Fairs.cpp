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

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int subtree_size[MAXN];
int a, b;
int pa, pb;
int ta, tb;

void dfs(int u, int p, int& t, int x, int& num) {
    subtree_size[u] = 1;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, t, x, num);
            subtree_size[u] += subtree_size[v];
        }
    }
    if (u == x) num = subtree_size[u];
    t += (u != a && u != b);
}

void solve(int n) {
    for (int i = 1; i <= n; i++) adj[i].clear();
    cin >> n >> ta >> a >> b;
    pa = pb = -1;
    for (int i = 0; i < ta; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ta = tb = 0;
    dfs(a, -1, ta, b, pb);
    dfs(b, -1, tb, a, pa);
    int res = 1LL * pa * pb - 1LL * (n - 2 - pa - pb) * (n - 2 - pa - pb) / 2 - pa * (pa - 1) / 2 - pb * (pb - 1) / 2;
    cout << res / 2 << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve(MAXN);
    }
}