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

struct Cell {
    int x, y, dist;
};

int bfs(vector<string>& grid, int n, int m, queue<Cell>& q, vector<vector<bool>>& visited) {
    int max_dist = 0;
    while (!q.empty()) {
        Cell current = q.front();
        q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = current.x + dx[dir];
            int ny = current.y + dy[dir];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] != '#') {
                visited[nx][ny] = true;
                q.push({nx, ny, current.dist + 1});
                max_dist = max(max_dist, current.dist + 1);
            }
        }
    }
    return max_dist;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        vector<string> grid(m);
        queue<Cell> q;
        for (int i = 0; i < m; ++i) {
            cin >> grid[i];
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '&') {
                    q.push({j, i, 0});
                }
            }
        }
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i) {
            if (grid[0][i] != '#') {
                q.push({i, 0, 1});
                visited[i][0] = true;
            }
            if (grid[m-1][i] != '#') {
                q.push({i, m-1, 1});
                visited[i][m-1] = true;
            }
        }
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] != '#') {
                q.push({0, i, 1});
                visited[0][i] = true;
            }
            if (grid[i][n-1] != '#') {
                q.push({n-1, i, 1});
                visited[n-1][i] = true;
            }
        }
        int result = bfs(grid, n, m, q, visited);
        cout << result << endl;
    }
}