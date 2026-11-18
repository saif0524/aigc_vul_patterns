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

const int OO = 1e9;
const int MAXN = 65;
const int MAXM = 65;
const int MAXR = 100005;

int n, m, r;
int dist[MAXN][MAXN];
int cars[MAXM][MAXN][MAXN];
int dp[MAXN][MAXM];

void floyd_warshall() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void precalculate(int k) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = OO;
        }
    }
    for (int c = 1; c <= m; c++) {
        for (int i = 1; i <= n; i++) {
            dp[i][c] = min(dp[i][c], cars[c][i][i]);
        }
    }
    for (int t = 1; t <= k; t++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                for (int c = 1; c <= m; c++) {
                    dp[u][c] = min(dp[u][c], dp[v][c] + dist[u][v]);
                }
            }
            for (int u = 1; u <= n; u++) {
                for (int v = 1; v <= n; v++) {
                    for (int c1 = 1; c1 <= m; c1++) {
                        for (int c2 = 1; c2 <= m; c2++) {
                            dp[u][c2] = min(dp[u][c2], dp[v][c1] + cars[c2][u][v]);
                        }
                    }
                }
            }
        }
    }
}

int main(){
    ((void)0);
    ((void)0);
    
    cin >> n >> m >> r;
    for(int c=1;c<=m;c++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin >> cars[c][i][j];
            }
        }
    }
    memset(dist, OO, sizeof(dist));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j] = cars[1][i][j];
        }
    }
    floyd_warshall();
    
    while(r--){
        int s, t, k;
        cin >> s >> t >> k;
        precalculate(k);
        int ans = OO;
        for(int c=1;c<=m;c++){
            ans = min(ans, dp[s][c] + cars[c][s][t]);
        }
        cout << ans << "\n";
    }
}