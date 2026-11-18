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

const int MAXN = 16;
const int INF = 1e9;

int N, M;
vector<vector<pair<int, int>>> adj;

int dp[1 << MAXN][MAXN];

int solve(int mask, int pos) {
    if (mask == (1 << N) - 1 && pos == N - 1) return 0;
    if (dp[mask][pos] != -1) return dp[mask][pos];
    int res = INF;
    for (auto [next, cost] : adj[pos]) {
        if ((mask & (1 << next)) == 0) {
            res = min(res, cost + solve(mask | (1 << next), next));
        }
    }
    return dp[mask][pos] = res;
}

int main(){
    ((void)0);
    ((void)0);
    cin >> N >> M;
    adj.resize(N);
    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    memset(dp, -1, sizeof(dp));
    int ans = solve(1, 0);
    if (ans == INF) ans = -1;
    cout << ans;
}