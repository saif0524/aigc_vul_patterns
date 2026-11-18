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

int dp[21][21][2];
int vis[21][21];
int dirx[] = {0, 1};
int diry[] = {1, 0};
int W, H;

int solve(int x, int y, int taken, const vector<vector<int>>& grid) {
    if (x == W) {
        x = 0;
        y += 1;
        taken = 0;
    }
    if (y == H) {
        return 0;
    }
    
    if (vis[x][y] == taken) {
        return dp[x][y][taken];
    }
    int res = solve(x + 1, y, 0, grid);
    if (taken == 0) {
        bool canTake = true;
        for (int d = 0; d < 2; ++d) {
            int xx = x + dirx[d];
            int yy = y + diry[d];
            if (xx >= 0 && xx < W && yy >= 0 && yy < H && vis[xx][yy]) {
                canTake = false;
            }
        }
        if (canTake) {
            vis[x][y] = 1;
            res = max(res, grid[y][x] + solve(x + 1, y, 1, grid));
            vis[x][y] = 0;
        }
    }
    dp[x][y][taken] = res;
    vis[x][y] = taken;
    return res;
}

int main() {
    int N;
    cin >> N;
    for (int tc = 1; tc <= N; ++tc) {
        cin >> W >> H;
        vector<vector<int>> grid(H, vector<int>(W));
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                cin >> grid[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        int res = solve(0, 0, 0, grid);
        cout << "Case " << tc << ": " << res << "\n";
    }
    return 0;
}