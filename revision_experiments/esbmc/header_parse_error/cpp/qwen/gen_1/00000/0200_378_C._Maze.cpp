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

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> grid(n);
    for(auto &s : grid) cin >> s;
    
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    queue<pair<int, int>> bfs;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(grid[i][j] == '.'){
                bfs.push({i, j});
                visited[i][j] = true;
                break;
            }
        }
        if(!bfs.empty()) break;
    }
    
    vector<pair<int, int>> edges;
    while(!bfs.empty()){
        auto [x, y] = bfs.front();
        bfs.pop();
        for(int dir = 0; dir < 4; ++dir){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(grid[nx][ny] == '.' && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    bfs.push({nx, ny});
                }
                else if(grid[nx][ny] == '#'){
                    edges.push_back({x, y});
                }
            }
        }
    }
    
    for(int i = 0; i < k; ++i){
        auto [x, y] = edges[i];
        grid[x][y] = 'X';
    }
    
    for(const auto &s : grid) cout << s << "\n";
}