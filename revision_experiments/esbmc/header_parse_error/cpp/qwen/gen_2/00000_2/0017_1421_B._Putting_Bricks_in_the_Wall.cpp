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

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool is_valid(int x, int y, int n) {
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

bool can_reach(vector<vector<char>>& grid, int n, int digit) {
    vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));
    queue<pair<int, int>> q;
    q.push({1, 1});
    visited[1][1] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == n && y == n) return true;

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (is_valid(nx, ny, n) && !visited[nx][ny]) {
                if (grid[nx][ny] == 'F' || grid[nx][ny] == 'S' || grid[nx][ny] - '0' == digit) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<char>> grid(n + 1, vector<char>(n + 1));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> grid[i][j];
            }
        }
        bool zero_reach = can_reach(grid, n, 0);
        bool one_reach = can_reach(grid, n, 1);
        vector<pair<int,int>> changes;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(grid[i][j] == 'S' || grid[i][j] == 'F') continue;
                int prev = grid[i][j] - '0';
                grid[i][j] = 1 - prev + '0';
                bool new_zero_reach = can_reach(grid, n, 0);
                bool new_one_reach = can_reach(grid, n, 1);
                if(!new_zero_reach && !new_one_reach){
                    changes.push_back({i, j});
                    break;
                }
                grid[i][j] = prev + '0';
            }
            if(changes.size() == 1) break;
        }
        if(changes.size() == 1){
            cout << "1\n";
            cout << changes[0].first << " " << changes[0].second << "\n";
            continue;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(grid[i][j] == 'S' || grid[i][j] == 'F') continue;
                int prev = grid[i][j] - '0';
                grid[i][j] = 1 - prev + '0';
                zero_reach = can_reach(grid, n, 0);
                one_reach = can_reach(grid, n, 1);
                if(!zero_reach && !one_reach){
                    changes.push_back({i, j});
                    break;
                }
                grid[i][j] = prev + '0';
            }
            if(changes.size() == 2) break;
        }
        if(changes.size() == 2){
            cout << "2\n";
            cout << changes[0].first << " " << changes[0].second << "\n";
            cout << changes[1].first << " " << changes[1].second << "\n";
            continue;
        }
        cout << "0\n";
    }
}