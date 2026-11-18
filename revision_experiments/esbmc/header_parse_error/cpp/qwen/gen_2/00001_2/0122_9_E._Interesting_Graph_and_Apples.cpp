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

const int N = 55;
vector<int> g[N];
int vis[N], par[N], comp[N], comp_cnt = 0, v_cnt[N];
vector<pair<int, int>> edges;
int find_cycle(int n) {
    int start = -1, end = -1;
    memset(vis, 0, sizeof(vis));
    memset(par, -1, sizeof(par));
    function<bool(int, int)> dfs = [&](int u, int p) {
        if (vis[u]) {
            start = u;
            end = p;
            return true;
        }
        par[u] = p;
        vis[u] = 1;
        for (int v : g[u]) {
            if (v != p) {
                if (dfs(v, u)) return true;
            }
        }
        return false;
    };
    for (int i = 1; i <= n; ++i) {
        if (!vis[i] && dfs(i, -1)) {
            return start;
        }
    }
    return -1;
}
void mark_comp(int u, int c) {
    if (comp[u]) return;
    comp[u] = c;
    ++v_cnt[c];
    for (int v : g[u]) mark_comp(v, c);
}
bool check(int n, int m) {
    memset(comp, 0, sizeof(comp));
    memset(v_cnt, 0, sizeof(v_cnt));
    comp_cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (!comp[i]) {
            ++comp_cnt;
            mark_comp(i, comp_cnt);
        }
    }
    if (comp_cnt != 1) return false;
    for (int i = 1; i <= comp_cnt; ++i) {
        if (v_cnt[i] != m) return false;
    }
    return true;
}
int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        if(u > v) swap(u, v);
        edges.push_back({u, v});
    }
    if(m != n){
        cout << "NO";
        return 0;
    }
    int start = find_cycle(n);
    if(start == -1){
        cout << "NO";
        return 0;
    }
    vector<pair<int, int>> cycle;
    do {
        cycle.push_back({start, par[start]});
        int next = par[start];
        par[start] = -2;
        start = next;
    } while (start != -2);
    set<pair<int, int>> s(edges.begin(), edges.end());
    vector<pair<int, int>> ans;
    for(int i=0;i<cycle.size()-1;i++){
        int u = cycle[i].first, v = cycle[i].second;
        if(u > v) swap(u, v);
        if(!s.count({u, v})){
            ans.push_back({u, v});
        }
    }
    for(auto [u, v]: cycle){
        int x = u, y = v;
        if(x > y) swap(x, y);
        if(!s.count({x, y})){
            ans.push_back({u, v});
        }
    }
    if(ans.size() == 0){
        cout << "YES\n0";
        return 0;
    }
    sort(ans.begin(), ans.end());
    if(!check(n, m + ans.size())){
        cout << "NO";
        return 0;
    }
    cout << "YES\n" << ans.size() << "\n";
    for(auto [u, v]: ans){
        cout << u << " " << v << "\n";
    }
}