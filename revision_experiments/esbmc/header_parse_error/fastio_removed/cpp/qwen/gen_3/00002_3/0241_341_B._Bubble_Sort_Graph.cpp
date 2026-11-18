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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n-1; ++i) {
        if (a[i] > a[i+1]) {
            adj[a[i]].push_back(a[i+1]);
            adj[a[i+1]].push_back(a[i]);
            swap(a[i], a[i+1]);
        }
    }
    vector<int> dp(n+1, 1);
    vector<bool> visited(n+1, false);
    function<int(int)> dfs = [&](int v) {
        if (visited[v]) return dp[v];
        visited[v] = true;
        for (int u : adj[v]) {
            dp[v] = max(dp[v], 1 + dfs(u));
        }
        return dp[v];
    };
    int result = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            result += dfs(i);
        }
    }
    cout << result;
}