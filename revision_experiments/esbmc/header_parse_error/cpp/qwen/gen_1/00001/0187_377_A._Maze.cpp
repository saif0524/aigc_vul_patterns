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

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y, int n, int m, vector<string>& grid, vector<vector<int>>& vis) {
    stack<pair<int, int>> s;
    s.push({x, y});
    vis[x][y] = 1;
    while (!s.empty()) {
        auto [cx, cy] = s.top();
        s.pop();
        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.' && !vis[nx][ny]) {
                s.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }
    }
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> grid(n);
    for(auto &row: grid) cin >> row;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == '.' && !vis[i][j]){
                dfs(i, j, n, m, grid, vis);
            }
        }
    }
    int added = 0;
    for(int i=0; i<n && added < k; i++){
        for(int j=0; j<m && added < k; j++){
            if(grid[i][j] == '.'){
                bool canChange = true;
                for(int d=0; d<4; d++){
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if(ni >= 0 && ni < n && nj >= 0 && nj < m && (vis[ni][nj] != vis[i][j])){
                        canChange = false;
                        break;
                    }
                }
                if(canChange){
                    grid[i][j] = 'X';
                    added++;
                }
            }
        }
    }
    for(auto &row: grid) cout << row << endl;
}