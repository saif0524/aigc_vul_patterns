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

const int MAXN = 3010;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool vis[MAXN][MAXN];
int grid[MAXN][MAXN];
int r, c, n;

bool bfs() {
    queue<pair<int, int>> q;
    memset(vis, 0, sizeof(vis));
    for (int j = 1; j <= c; j++) {
        if (grid[1][j] == 0) {
            q.push({1, j});
            vis[1][j] = true;
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (x == r) return true;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 1 || nx > r || ny < 1 || ny > c || grid[nx][ny] == 1) continue;
            if (vis[nx][ny]) continue;
            vis[nx][ny] = true;
            q.push({nx, ny});
        }
        if (y == 1) {
            int nx = x, ny = c;
            if (grid[nx][ny] == 0 && !vis[nx][ny]) {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        if (y == c) {
            int nx = x, ny = 1;
            if (grid[nx][ny] == 0 && !vis[nx][ny]) {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> r >> c >> n;
    int ans = 0;
    while (n--) {
        int x, y;
        cin >> x >> y;
        grid[x][y] = 1;
        if (!bfs()) {
            grid[x][y] = 0;
        } else {
            ans++;
        }
    }
    cout << ans;
}