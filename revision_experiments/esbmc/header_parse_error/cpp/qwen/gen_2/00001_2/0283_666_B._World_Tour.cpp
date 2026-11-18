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
const int N = 3005;
int dist[N][N];

void floyd_warshall(int n) {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        dist[u][v] = 1;
    }
    floyd_warshall(n);
    int max_dist = -1;
    vector<int> best_tour;
    for(int a=1;a<=n;a++){
        for(int b=1;b<=n;b++){
            if(a==b) continue;
            for(int c=1;c<=n;c++){
                if(c==a || c==b) continue;
                for(int d=1;d<=n;d++){
                    if(d==a || d==b || d==c) continue;
                    int current_dist = dist[a][b] + dist[b][c] + dist[c][d];
                    if(current_dist > max_dist){
                        max_dist = current_dist;
                        best_tour = {a, b, c, d};
                    }
                }
            }
        }
    }
    for(auto city : best_tour){
        cout << city << " ";
    }
    cout << "\n";
}