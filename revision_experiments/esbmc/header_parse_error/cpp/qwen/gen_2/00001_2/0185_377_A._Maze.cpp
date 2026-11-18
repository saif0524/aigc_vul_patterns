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
    for(auto &row: grid) cin >> row;
    
    vector<pair<int, int>> empties;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(grid[i][j] == '.') empties.push_back({i, j});
        }
    }
    
    vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    auto valid = [&](int i, int j){
        return i>=0 && i<n && j>=0 && j<m && grid[i][j] == '.';
    };
    
    vector<bool> visited(empties.size());
    queue<int> q;
    q.push(0);
    visited[0] = true;
    
    while(q.size() && k > 0){
        int id = q.front();
        q.pop();
        auto [x, y] = empties[id];
        bool is_boundary = false;
        for(auto [dx, dy]: directions){
            int nx = x + dx, ny = y + dy;
            if(valid(nx, ny)){
                is_boundary = true;
                break;
            }
        }
        
        if(is_boundary){
            grid[x][y] = 'X';
            k--;
        }
        
        for(auto [dx, dy]: directions){
            int nx = x + dx, ny = y + dy;
            for(int j=0; j<empties.size(); ++j){
                if(!visited[j] && empties[j].first == nx && empties[j].second == ny){
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
    }
    
    for(auto &row: grid) cout << row << '\n';
}