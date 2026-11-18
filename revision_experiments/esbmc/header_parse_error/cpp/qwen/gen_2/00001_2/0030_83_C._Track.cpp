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

bool isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> grid(n);
    int sx, sy, tx, ty;
    for(int i = 0; i < n; ++i){
        cin >> grid[i];
        for(int j = 0; j < m; ++j){
            if(grid[i][j] == 'S'){
                sx = i;
                sy = j;
            }
            if(grid[i][j] == 'T'){
                tx = i;
                ty = j;
            }
        }
    }

    using State = tuple<int, int, int, int, vector<char>>;
    priority_queue<State, vector<State>, greater<>> pq;
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(1 << 4, false)));
    pq.emplace(0, sx, sy, 0, vector<char>());
    visited[sx][sy][0] = true;

    while(!pq.empty()){
        auto [dist, x, y, mask, path] = pq.top();
        pq.pop();

        if(x == tx && y == ty){
            for(char c : path){
                cout << c;
            }
            return 0;
        }

        for(int dir = 0; dir < 4; ++dir){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(isValid(nx, ny, n, m) && grid[nx][ny] != 'S'){
                int newMask = mask;
                char c = grid[nx][ny];
                if(c != 'T'){
                    newMask |= (1 << (c - 'a'));
                }
                int cnt = __builtin_popcount(newMask);

                if(cnt <= k && !visited[nx][ny][newMask]){
                    visited[nx][ny][newMask] = true;
                    vector<char> newPath = path;
                    if(c != 'T'){
                        newPath.push_back(c);
                    }
                    pq.emplace(dist + 1, nx, ny, newMask, newPath);
                }
            }
        }
    }
    cout << "-1";
}