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

const int N = 200005;

vector<int> g[N];
int color[N];
bool bad = false;

void dfs(int u, int c) {
    color[u] = c;
    for (auto v : g[u]) {
        if (color[v] == c) {
            bad = true;
            return;
        }
        if (color[v] == -1) dfs(v, c ^ 1);
    }
}

int main() {
    ((void)0);
    ((void)0);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
        g[edges[i].first - 1].push_back(edges[i].second - 1);
        g[edges[i].second - 1].push_back(edges[i].first - 1);
    }

    memset(color, -1, sizeof(color));
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) dfs(i, 0);
    }

    if (bad) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    string ans;
    for (auto e : edges) {
        if (color[e.first - 1] == 0) ans.push_back('0');
        else ans.push_back('1');
    }
    cout << ans << "\n";

    return 0;
}