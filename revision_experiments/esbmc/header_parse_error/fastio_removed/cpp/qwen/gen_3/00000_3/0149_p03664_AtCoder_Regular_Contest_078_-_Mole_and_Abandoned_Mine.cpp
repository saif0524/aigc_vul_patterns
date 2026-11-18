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

const int MAXN = 15;
const int INF = 1e9;
int n, m;
vector<tuple<int, int, int>> edges;
int dp[1<<MAXN][MAXN];

int main(){
    ((void)0);
    ((void)0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        edges.emplace_back(u, v, c);
    }
    for(int i = 0; i < (1<<n); i++)
        for(int j = 0; j < n; j++)
            dp[i][j] = INF;
    dp[1][0] = 0;
    for(int mask = 0; mask < (1<<n); mask++){
        for(auto [u, v, c] : edges){
            if(mask & (1<<u) && mask & (1<<v)){
                int mask2 = mask ^ (1<<u);
                dp[mask][v] = min(dp[mask][v], dp[mask2][u] + c);
                mask2 = mask ^ (1<<v);
                dp[mask][u] = min(dp[mask][u], dp[mask2][v] + c);
            }
        }
    }
    cout << dp[(1<<n) - 1][n-1] << "\n";
}