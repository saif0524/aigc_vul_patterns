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

const int MAXR = 3005;
const int MAXC = 3005;
int r, c, n;
vector<pair<int, int>> cells;
vector<vector<char>> grid;
vector<vector<bool>> visited;

int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

bool is_valid(int x, int y) {
    if (x >= 1 && x <= r && y >= 1 && y <= c) {
        if (y == 1 && grid[x][c] == '.' && grid[x][y] == '.') return true;
        return grid[x][y] == '.';
    }
    return false;
}

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (is_valid(nx, ny) && !visited[nx][ny]) {
            dfs(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c >> n;
    grid.assign(r + 1, vector<char>(c + 1, '.'));
    visited.assign(r + 1, vector<bool>(c + 1, false));

    cells.resize(n);
    for (auto& [ri, ci] : cells) {
        cin >> ri >> ci;
    }

    int ans = 0;
    for (auto& [ri, ci] : cells) {
        grid[ri][ci] = 'X';
        visited.assign(r + 1, vector<bool>(c + 1, false));

        bool found = false;
        for (int j = 1; j <= c && !found; j++) {
            if (grid[1][j] == '.') {
                dfs(1, j);
                found = visited[r][j];
            }
        }

        if (found) {
            ans++;
        } else {
            grid[ri][ci] = '.';
        }
    }

    cout << ans;
}