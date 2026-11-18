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

int main(){
    ((void)0);
    ((void)0);
    int n;
    cin >> n;
    vector<ll> b(n), a(n);
    for(auto &x: b) cin >> x;
    for(auto &x: a) cin >> x;
    vector<vector<pair<int, ll>>> g(n);
    for(int i=1;i<n;i++){
        int x;
        ll k;
        cin >> x >> k;
        x--;
        g[x].push_back({i, k});
        g[i].push_back({x, 1});
    }
    vector<ll> total(n, 0);
    function<void(int, int)> dfs = [&](int u, int p){
        total[u] = b[u] - a[u];
        for(auto [v, k]: g[u]){
            if(v == p) continue;
            dfs(v, u);
            total[u] += (total[v] + k-1) / k;
        }
    };
    dfs(0, -1);
    cout << (total[0] >= 0 ? "YES" : "NO");
}