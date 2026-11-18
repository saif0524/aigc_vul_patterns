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
typedef long long ll;
const int MOD = 100000007;
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

bool isValid(int x, int y, int r, int c) {
    return (x >= 0 && x < r && y >= 0 && y < c);
}

int main(){
    ((void)0);
    ((void)0);
    int r, c, a1, a2, b1, b2;
    cin >> r >> c >> a1 >> a2 >> b1 >> b2;
    vector<vector<ll>> dist(r, vector<ll>(c, -1));
    vector<vector<ll>> ways(r, vector<ll>(c, 0));
    queue<pair<int, int>> q;
    q.push({a1, a2});
    dist[a1][a2] = 0;
    ways[a1][a2] = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dr[i];
            int ny = y + dc[i];
            if(nx < 0) nx = r - 1;
            if(ny < 0) ny = c - 1;
            if(nx >= r) nx = 0;
            if(ny >= c) ny = 0;
            if(dist[nx][ny] == -1 || dist[nx][ny] == dist[x][y] + 1){
                if(dist[nx][ny] == -1){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
                ways[nx][ny] = (ways[nx][ny] + ways[x][y]) % MOD;
            }
        }
    }
    cout << ways[b1][b2] << "\n";
    return 0;
}