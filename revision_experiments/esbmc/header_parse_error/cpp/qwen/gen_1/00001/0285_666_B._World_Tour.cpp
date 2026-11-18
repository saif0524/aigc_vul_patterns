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

const int MAXN = 3005;
const int INF = 1e9;

int n, m;
vector<int> g[MAXN];
int dist[MAXN][MAXN];

void floyd_warshall() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dist[i][j] = (i == j) ? 0 : INF;
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        dist[u][v] = 1;
    }
    floyd_warshall();
    int max_dist = 0;
    vector<int> path;
    for(int a=1;a<=n;a++){
        for(int b=1;b<=n;b++){
            if(a == b || dist[a][b] == INF) continue;
            for(int c=1;c<=n;c++){
                if(c == a || c == b || dist[b][c] == INF) continue;
                for(int d=1;d<=n;d++){
                    if(d == a || d == b || d == c || dist[c][d] == INF) continue;
                    int total_dist = dist[a][b] + dist[b][c] + dist[c][d];
                    if(total_dist > max_dist){
                        max_dist = total_dist;
                        path = {a, b, c, d};
                    }
                }
            }
        }
    }
    for(int city : path)
        cout << city << " ";
    return 0;
}