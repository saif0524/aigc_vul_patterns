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

bool bfs(int n, vector<vector<char>> &grid, int choose){
    queue<pair<int, int>> q;
    q.push({0, 0});
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[0][0] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x == n-1 && y == n-1){
            return true;
        }

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]){
                if((nx == 0 && ny == 0) || (nx == n-1 && ny == n-1) || grid[nx][ny] - '0' == choose){
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
        vector<vector<char>> grid(n, vector<char>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> grid[i][j];
            }
        }

        int changes = 0;
        vector<pair<int, int>> changesList;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if((i == 0 && j == 0) || (i == n-1 && j == n-1)){
                    continue;
                }
                if(grid[i][j] == '0'){
                    grid[i][j] = '1';
                    if(!bfs(n, grid, 0) && !bfs(n, grid, 1)){
                        changes = 1;
                        changesList.clear();
                        changesList.push_back({i+1, j+1});
                    }
                    grid[i][j] = '0';
                }
                else if(grid[i][j] == '1'){
                    grid[i][j] = '0';
                    if(!bfs(n, grid, 0) && !bfs(n, grid, 1)){
                        changes = 1;
                        changesList.clear();
                        changesList.push_back({i+1, j+1});
                    }
                    grid[i][j] = '1';
                }

                if(changes == 1){
                    break;
                }
            }
            if(changes == 1){
                break;
            }
        }

        if(changes == 0){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if((i == 0 && j == 0) || (i == n-1 && j == n-1)){
                        continue;
                    }
                    for(int x = i; x < n; x++){
                        for(int y = (x == i ? j+1 : 0); y < n; y++){
                            if((x == 0 && y == 0) || (x == n-1 && y == n-1)){
                                continue;
                            }
                            int a = grid[i][j] - '0';
                            int b = grid[x][y] - '0';
                            grid[i][j] = '1' - a;
                            grid[x][y] = '1' - b;
                            if(!bfs(n, grid, 0) && !bfs(n, grid, 1)){
                                changes = 2;
                                changesList.clear();
                                changesList.push_back({i+1, j+1});
                                changesList.push_back({x+1, y+1});
                            }
                            grid[i][j] = a + '0';
                            grid[x][y] = b + '0';

                            if(changes == 2){
                                break;
                            }
                        }
                        if(changes == 2){
                            break;
                        }
                    }
                    if(changes == 2){
                        break;
                    }
                }
                if(changes == 2){
                    break;
                }
            }
        }

        cout << changes << "\n";
        for(auto &p : changesList){
            cout << p.first << " " << p.second << "\n";
        }
    }

    return 0;
}