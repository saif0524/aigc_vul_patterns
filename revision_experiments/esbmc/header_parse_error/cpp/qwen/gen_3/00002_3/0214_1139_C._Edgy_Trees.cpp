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

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

vector<pair<int, int>> adj[MAXN];
vector<int> blackDfs, redDfs;
int blackDist[MAXN], redDist[MAXN], visited[MAXN];

void dfs(int node, int parent, int color, vector<int> &dist, int *dfs) {
    visited[node] = 1;
    dist[node] = color;
    dfs.push_back(node);
    for (auto &edge : adj[node]) {
        int neighbor = edge.first, edgeColor = edge.second;
        if (!visited[neighbor]) {
            dfs(neighbor, node, color + edgeColor, dist, dfs);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n-1; ++i){
        int u, v, x;
        cin >> u >> v >> x;
        adj[u].emplace_back(v, x);
        adj[v].emplace_back(u, x);
    }
    dfs(1, -1, 0, blackDist, blackDfs);
    memset(visited, 0, sizeof(visited));
    dfs(1, -1, 0, redDist, redDfs);
    int blackNodes = blackDfs.size(), redNodes = redDfs.size();
    long long totalSequences = 1, blackSequences = 1;
    for(int i=0; i<k; ++i){
        totalSequences = (totalSequences * n) % MOD;
        blackSequences = (blackSequences * blackNodes) % MOD;
    }
    long long goodSequences = (totalSequences - blackSequences + MOD) % MOD;
    cout << goodSequences;
}