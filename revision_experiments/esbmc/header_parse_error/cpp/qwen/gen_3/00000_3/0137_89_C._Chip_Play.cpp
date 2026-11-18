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

const int N = 5005;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const char dir[] = {'R', 'L', 'D', 'U'};

int n, m;
char grid[N][N];
bool visited[N][N];

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '.';
}

int bfs(int x, int y) {
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    
    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        cnt++;
        
        for (int d = 0; d < 4; ++d) {
            if (grid[cx][cy] == dir[d]) {
                int nx = cx + dx[d];
                int ny = cy + dy[d];
                int closestDist = 1e9;
                int closestX = -1, closestY = -1;
                
                while (isValid(nx, ny)) {
                    if (grid[nx][ny] == dir[d]) {
                        int dist = abs(nx - cx) + abs(ny - cy);
                        if (dist < closestDist) {
                            closestDist = dist;
                            closestX = nx;
                            closestY = ny;
                        }
                    }
                    nx += dx[d];
                    ny += dy[d];
                }
                
                if (closestX != -1 && !visited[closestX][closestY]) {
                    q.push({closestX, closestY});
                    visited[closestX][closestY] = true;
                }
            }
        }
    }
    
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    
    int maxPoints = 0;
    int maxMoves = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] != '.') {
                memset(visited, false, sizeof(visited));
                int points = bfs(i, j);
                if (points > maxPoints) {
                    maxPoints = points;
                    maxMoves = 1;
                } else if (points == maxPoints) {
                    maxMoves++;
                }
            }
        }
    }
    
    cout << maxPoints << " " << maxMoves;
}