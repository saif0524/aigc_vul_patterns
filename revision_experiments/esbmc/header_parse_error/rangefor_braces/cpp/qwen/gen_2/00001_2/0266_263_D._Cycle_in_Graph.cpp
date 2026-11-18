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
vector<bool> visited;
vector<int> path;
int k, found_cycle = 0;

void dfs(int u, int p) {
    if (found_cycle) return;
    visited[u] = true;
    path.push_back(u);
    for (int v : adj[u]) {
        if (v == p) continue;
        if (visited[v]) {
            int index = find(path.begin(), path.end(), v) - path.begin();
            if (path.size() - index >= k + 1) {
                found_cycle = 1;
                path.erase(path.begin(), path.begin() + index);
                return;
            }
        } else {
            dfs(v, u);
        }
    }
    if (!found_cycle) path.pop_back();
}

int main(){
    ((void)0);
    ((void)0);
    int n, m;
    cin >> n >> m >> k;
    adj.resize(n + 1);
    visited.resize(n + 1, false);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n && !found_cycle; i++){
        if(!visited[i]){
            dfs(i, -1);
        }
    }
    cout << path.size() << "\n";
    for(int i : path) { cout << i << " "; }
    return 0;
}