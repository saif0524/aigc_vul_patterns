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

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN], rev_adj[MAXN];
bool visited[MAXN], rev_visited[MAXN];
int n, m;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

void rev_dfs(int u, vector<int>& path) {
    rev_visited[u] = true;
    path.push_back(u);
    for (int v : rev_adj[u]) {
        if (!rev_visited[v]) {
            rev_dfs(v, path);
        }
    }
}

bool is_interesting(int u) {
    vector<int> path;
    rev_dfs(u, path);
    return path.size() == n;
}

int main() {
    ((void)0);
    ((void)0);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            rev_adj[i].clear();
            visited[i] = false;
            rev_visited[i] = false;
        }

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            rev_adj[v].push_back(u);
        }

        int interesting_cnt = 0;
        vector<int> interesting_cities;

        for (int i = 1; i <= n; i++) {
            if (is_interesting(i)) {
                interesting_cnt++;
                interesting_cities.push_back(i);
            }
        }

        if (interesting_cnt < 0.2 * n) {
            cout << "-1\n";
        } else {
            sort(interesting_cities.begin(), interesting_cities.end());
            for (int city : interesting_cities) {
                cout << city << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}