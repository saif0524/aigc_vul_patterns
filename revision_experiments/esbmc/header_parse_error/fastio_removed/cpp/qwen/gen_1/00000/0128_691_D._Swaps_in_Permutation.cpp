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

int main() {
    ((void)0);
    ((void)0);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> p(n);
    for (int &x : p) cin >> x;
    
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<bool> visited(n);
    vector<vector<int>> components;
    function<void(int)> dfs = [&](int v) {
        visited[v] = true;
        components.back().push_back(v);
        for (int u : adj[v]) {
            if (!visited[u]) {
                dfs(u);
            }
        }
    };
    
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            components.emplace_back();
            dfs(i);
        }
    }
    
    for (auto &comp : components) {
        vector<int> values;
        for (int v : comp) {
            values.push_back(p[v]);
        }
        sort(values.rbegin(), values.rend());
        sort(comp.begin(), comp.end(), [&](int x, int y) { return p[x] > p[y]; });
        for (int i = 0; i < comp.size(); ++i) {
            p[comp[i]] = values[i];
        }
    }
    
    for (int x : p) cout << x << ' ';
    cout << '\n';
    
    return 0;
}