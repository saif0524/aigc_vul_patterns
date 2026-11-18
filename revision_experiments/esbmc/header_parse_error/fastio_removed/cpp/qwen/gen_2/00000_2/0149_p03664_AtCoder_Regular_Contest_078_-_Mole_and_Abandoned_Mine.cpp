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

const int N = 16;
vector<pair<int, int>> adj[N];
int dp[1 << N][N];
bool vis[1 << N][N];

int solve(int mask, int node) {
    if (vis[mask][node]) return dp[mask][node];
    vis[mask][node] = true;
    dp[mask][node] = 1e9;
    if (node == N-1 && mask == (1<<N)-1) return dp[mask][node] = 0;
    for(auto [nxt, cost] : adj[node]) {
        if(mask & (1 << nxt)) continue;
        dp[mask][node] = min(dp[mask][node], cost + solve(mask | (1 << nxt), nxt));
    }
    return dp[mask][node];
}

int main(){
    ((void)0);
    ((void)0);
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    memset(dp, 0, sizeof(dp));
    memset(vis, false, sizeof(vis));
    int ans = solve(1, 0);
    cout << (ans >= 1e9 ? -1 : ans) << "\n";
}