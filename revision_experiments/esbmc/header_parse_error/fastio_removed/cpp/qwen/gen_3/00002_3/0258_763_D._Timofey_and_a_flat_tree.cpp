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

vector<vector<int>> adj;
vector<unordered_map<string, int>> cnt;
vector<int> ans;
string dfs(int u, int p) {
    string s = "(";
    for (auto &v : adj[u]) {
        if (v == p) continue;
        s += dfs(v, u);
    }
    s += ")";
    if (cnt[u].count(s) == 0) cnt[u][s] = cnt[u].size();
    ans[u]++;
    ans[u] -= cnt[u].size() - cnt[u][s];
    return to_string(cnt[u][s]);
}

int main() {
    ((void)0);
    ((void)0);
    int n;
    cin >> n;
    adj.resize(n);
    cnt.resize(n);
    ans.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);
    int best = 0;
    for (int i = 1; i < n; i++) {
        if (ans[i] > ans[best]) best = i;
    }
    cout << best + 1;
}