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

struct Point {
    int x, y, z;
};

const int dx[] = {1, 0, 0};
const int dy[] = {0, 1, 0};
const int dz[] = {0, 0, 1};

bool isValid(int x, int y, int z, int n, int m, int k) {
    return x >= 0 && x < n && y >= 0 && y < m && z >= 0 && z < k;
}

bool bfs(vector<vector<vector<char>>>& grid, int x, int y, int z, int n, int m, int k, vector<vector<vector<bool>>>& visited) {
    queue<Point> q;
    q.push({x, y, z});
    visited[x][y][z] = true;
    while (!q.empty()) {
        Point p = q.front();
        q.pop();
        for (int i = 0; i < 3; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            int nz = p.z + dz[i];
            if (isValid(nx, ny, nz, n, m, k) && grid[nx][ny][nz] == '1' && !visited[nx][ny][nz]) {
                q.push({nx, ny, nz});
                visited[nx][ny][nz] = true;
            }
        }
    }
    return true;
}

int main() {
    ((void)0);
    ((void)0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<vector<char>>> grid(n, vector<vector<char>>(m, vector<char>(k)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int l = 0; l < k; l++) {
                cin >> grid[i][j][l];
            }
        }
        cin.ignore();
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int l = 0; l < k; l++) {
                if (grid[i][j][l] == '0') continue;
                grid[i][j][l] = '0';
                vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(k, false)));
                int total = 0;
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < m; y++) {
                        for (int z = 0; z < k; z++) {
                            if (grid[x][y][z] == '1' && !visited[x][y][z]) {
                                bfs(grid, x, y, z, n, m, k, visited);
                                total++;
                            }
                        }
                    }
                }
                if (total > 1) count++;
                grid[i][j][l] = '1';
            }
        }
    }
    cout << count << endl;
    return 0;
}