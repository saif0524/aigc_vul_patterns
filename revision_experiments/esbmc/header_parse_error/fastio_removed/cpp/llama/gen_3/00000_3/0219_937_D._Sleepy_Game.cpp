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

const int N = 1e5 + 5;

vector<int> g[N];
int dp[N], d[N];

void dfs(int v) {
    if (d[v] == 1) return;
    d[v] = 1;
    for (auto u : g[v]) {
        dfs(u);
        if (dp[u] == 0) dp[v] = 1;
        else if (dp[u] == -1) dp[v] = -1;
        else if (dp[u] == 1) {
            if (dp[v] != -1) dp[v] = 0;
        }
    }
    if (dp[v] != -1) dp[v] = d[v] = 0;
}

int main() {
    ((void)0);
    ((void)0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        g[i].resize(k);
        for (auto &j : g[i]) {
            cin >> j;
            j--;
        }
    }
    int s;
    cin >> s;
    s--;
    for (int i = 0; i < n; ++i) {
        dp[i] = -1;
        d[i] = 0;
    }
    dfs(s);
    if (dp[s] == 1) {
        cout << "Win\n";
        vector<int> p;
        function<void(int)> print = [&](int v) {
            p.push_back(v);
            if (dp[v] == 0) return;
            for (auto u : g[v]) {
                if (dp[u] == 0) {
                    print(u);
                    return;
                }
            }
        };
        print(s);
        for (auto &i : p) cout << i + 1 << ' ';
        cout << '\n';
    } else if (dp[s] == 0) {
        cout << "Draw\n";
    } else {
        cout << "Lose\n";
    }
    return 0;
}