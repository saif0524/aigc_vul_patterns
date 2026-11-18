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

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool canReach(vector<vector<char>>& grid, int n, int val) {
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    q.push({0, 0});
    vis[0][0] = true;
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        if (x == n - 1 && y == n - 1) return true;
        
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny]) {
                if (nx == 0 && ny == 0) {
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                } else if (nx == n - 1 && ny == n - 1) {
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                } else {
                    if (grid[nx][ny] - '0' == val) {
                        q.push({nx, ny});
                        vis[nx][ny] = true;
                    }
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
        vector<vector<char>> grid(n, vector<char>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> grid[i][j];
            }
        }
        if(!canReach(grid, n, 0) && !canReach(grid, n, 1)){
            cout << "0\n";
            continue;
        }
        vector<pair<int, int>> changes;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i == 0 && j == 0) continue;
                if(i == n-1 && j == n-1) continue;
                if(grid[i][j] == '0') grid[i][j] = '1';
                else grid[i][j] = '0';
                if(!canReach(grid, n, 0) && !canReach(grid, n, 1)){
                    changes.push_back({i+1, j+1});
                    if(changes.size() == 2) break;
                }
                if(grid[i][j] == '0') grid[i][j] = '1';
                else grid[i][j] = '0';
            }
            if(changes.size() == 2) break;
        }
        cout << changes.size() << "\n";
        for(auto [x, y]: changes){
            cout << x << " " << y << "\n";
        }
    }
}