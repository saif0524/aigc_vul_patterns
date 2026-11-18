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

const int MAXN = 100005;
vector<vector<pair<int, int>>> adj(MAXN);
vector<bool> vis(MAXN, false);
vector<bool> bridge(MAXN, false);
vector<int> low(MAXN), num(MAXN);
int counter = 0;

void dfs(int node, int prev, int pnum) {
    vis[node] = true;
    num[node] = low[node] = counter++;
    for (auto& edge : adj[node]) {
        int neighbor = edge.first;
        int edge_num = edge.second;
        if (!vis[neighbor]) {
            dfs(neighbor, node, edge_num);
            low[node] = min(low[node], low[neighbor]);
            if (low[neighbor] > num[node]) {
                bridge[edge_num] = true;
            }
        } else if (neighbor != prev) {
            low[node] = min(low[node], num[neighbor]);
        }
    }
}

int main() {
    ((void)0);
    ((void)0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, -1, -1);
        }
    }
    vector<int> result;
    for (int i = 0; i < m; i++) {
        if (!bridge[i]) {
            result.push_back(i + 1);
        }
    }
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}