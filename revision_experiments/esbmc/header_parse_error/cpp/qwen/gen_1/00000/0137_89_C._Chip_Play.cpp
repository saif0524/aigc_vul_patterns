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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(auto &s : grid) cin >> s;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    map<char, int> dir_map = {{'R', 0}, {'L', 1}, {'D', 2}, {'U', 3}};
    int max_points = 0, max_moves = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == '.') continue;
            char dir = grid[i][j];
            grid[i][j] = '.';
            queue<pair<int, int>> q;
            q.push({i, j});
            int points = 0;
            while(!q.empty()){
                auto [x, y] = q.front();
                q.pop();
                points++;
                int nx = x + dx[dir_map[dir]];
                int ny = y + dy[dir_map[dir]];
                while(nx >= 0 && nx < n && ny >= 0 && ny < m){
                    if(grid[nx][ny] != '.'){
                        dir = grid[nx][ny];
                        q.push({nx, ny});
                        grid[nx][ny] = '.';
                        break;
                    }
                    nx += dx[dir_map[dir]];
                    ny += dy[dir_map[dir]];
                }
            }
            if(points > max_points){
                max_points = points;
                max_moves = 1;
            }else if(points == max_points){
                max_moves++;
            }
            grid[i][j] = dir;
        }
    }
    cout << max_points << ' ' << max_moves;
}