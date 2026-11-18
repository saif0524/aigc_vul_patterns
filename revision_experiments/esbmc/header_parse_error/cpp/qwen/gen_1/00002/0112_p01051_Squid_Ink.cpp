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

struct State {
    int x, y, d;
    bool operator<(const State &other) const {
        return d > other.d;
    }
};

int dijkstra(vector<vector<char>> &grid, int Sx, int Sy, int Gx, int Gy) {
    int R = grid.size();
    int C = grid[0].size();
    vector<vector<int>> dist(R, vector<int>(C, 1e9));
    priority_queue<State> pq;
    dist[Sx][Sy] = 0;
    pq.push({Sx, Sy, 0});

    while (!pq.empty()) {
        State cur = pq.top();
        pq.pop();
        if (cur.d > dist[cur.x][cur.y]) continue;

        if (cur.x == Gx && cur.y == Gy) break;

        for (int i = 0; i < 4; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx < 0 || ny < 0 || nx >= R || ny >= C || grid[nx][ny] == '#') continue;
            int nd = cur.d + (grid[nx][ny] == '.' ? 2 : 1);
            if (nd < dist[nx][ny]) {
                dist[nx][ny] = nd;
                pq.push({nx, ny, nd});
            }
        }

        for (int dir = 0; dir < 4; ++dir) {
            for (int j = 1; j <= 3; ++j) {
                int nx = cur.x + dx[dir] * j;
                int ny = cur.y + dy[dir] * j;
                if (nx < 0 || ny < 0 || nx >= R || ny >= C || grid[nx][ny] == '#' || grid[nx][ny] == 'x') break;
                if (grid[nx][ny] == '.') grid[nx][ny] = 'o';
            }
            int nd = cur.d + 2;
            pq.push({cur.x, cur.y, nd});
        }
    }
    return dist[Gx][Gy];
}

int main(){
    int R, C;
    cin >> R >> C;
    vector<vector<char>> grid(R, vector<char>(C));
    int Sx, Sy, Gx, Gy;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'S'){
                Sx = i;
                Sy = j;
            }
            if(grid[i][j] == 'G'){
                Gx = i;
                Gy = j;
            }
        }
    }
    cout << dijkstra(grid, Sx, Sy, Gx, Gy) << "\n";
}