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

const int INF = 1e9;
const int MAX_V = 110;
int V, E, k, d, dist[MAX_V][MAX_V], cakes[7], dp[1<<7][MAX_V];

struct Edge {
    int from, to, cost;
};

int main(){
    while(cin >> m >> n >> k >> d, m || n || k || d){
        V = m + n + 2;
        for(int i = 0; i < V; i++) for(int j = 0; j < V; j++) dist[i][j] = (i == j ? 0 : INF);
        for(int i = 0; i < m; i++) cin >> cakes[i];
        for(int i = 0; i < d; i++){
            string s, t; int e;
            cin >> s >> t >> e;
            int a = s[0] == 'C' ? s[1] - '0' : (s[0] == 'H' ? 0 : (s[0] == 'D' ? 1 : s[1] - '0' + m));
            int b = t[0] == 'C' ? t[1] - '0' : (t[0] == 'H' ? 0 : (t[0] == 'D' ? 1 : t[1] - '0' + m));
            dist[a][b] = dist[b][a] = e;
        }
        for(int k = 0; k < V; k++) for(int i = 0; i < V; i++) for(int j = 0; j < V; j++) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        int mask = (1<<m) - 1;
        for(int i = 0; i <= mask; i++) for(int j = 0; j < V; j++) dp[i][j] = INF;
        dp[0][0] = 0;
        for(int i = mask; i >= 0; i--) for(int j = 0; j < V; j++){
            if(dp[i][j] == INF) continue;
            dp[i][j] -= k * dist[j][1];
            for(int c = 0; c < m; c++) if(!(i & (1<<c)) && dist[j][c+2] < INF){
                dp[i|(1<<c)][c+2] = min(dp[i|(1<<c)][c+2], dp[i][j] + cakes[c] - k * dist[j][c+2]);
            }
        }
        int ans = INF;
        for(int i = 0; i <= mask; i++) ans = min(ans, dp[i][1]);
        cout << ans << "\n";
    }
}