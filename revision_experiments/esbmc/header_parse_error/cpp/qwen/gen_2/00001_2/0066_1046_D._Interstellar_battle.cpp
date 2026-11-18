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

typedef double db;
const int MAXN = 100005;

int n, q;
db p[MAXN];
vector<int> adj[MAXN];
db exp_kingdoms[MAXN];

db dfs(int u, int par) {
    db sum = p[u];
    for (int v : adj[u]) {
        if (v == par) continue;
        sum += dfs(v, u);
    }
    exp_kingdoms[u] = sum;
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i =0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);
    db total_exp = 0.0;
    for(int i =0; i < n; i++) total_exp += exp_kingdoms[i] * (1.0 - p[i]);
    cin >> q;
    while(q--){
        int u;
        db np;
        cin >> u >> np;
        total_exp -= exp_kingdoms[u] * (1.0 - p[u]);
        p[u] = np;
        db new_sum = p[u];
        for(int v : adj[u]){
            new_sum += exp_kingdoms[v];
        }
        total_exp += new_sum * (1.0 - p[u]);
        exp_kingdoms[u] = new_sum;
        cout << fixed << setprecision(5) << total_exp << "\n";
    }
    return 0;
}