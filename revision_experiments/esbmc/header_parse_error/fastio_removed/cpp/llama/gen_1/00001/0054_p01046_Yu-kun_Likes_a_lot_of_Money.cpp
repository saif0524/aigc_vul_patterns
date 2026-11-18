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

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int h, w, n, r;
char mp[10][10];
int x, y;
int cost[200];
bool vis[200];
int ans = 0;

void dfs(int sx, int sy, int sum, int rock) {
    ans = max(ans, sum);
    for (int i = 0; i < 4; ++i) {
        int nx = sx + dx[i], ny = sy + dy[i];
        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if (mp[nx][ny] == '#') continue;
        if (mp[nx][ny] == '*') {
            if (sum < rock + r) continue;
            mp[nx][ny] = '.';
            dfs(nx, ny, sum, rock + 1);
            mp[nx][ny] = '*';
        } else if (mp[nx][ny] >= '0' && mp[nx][ny] <= '9' || mp[nx][ny] >= 'a' && mp[nx][ny] <= 'z' || mp[nx][ny] >= 'A' && mp[nx][ny] <= 'Z') {
            if (vis[mp[nx][ny]]) continue;
            vis[mp[nx][ny]] = true;
            dfs(nx, ny, sum + cost[mp[nx][ny]], rock);
            vis[mp[nx][ny]] = false;
        } else {
            dfs(nx, ny, sum, rock);
        }
    }
}

int main() {
    ((void)0);
    ((void)0);
    cin >> h >> w >> n >> r;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> mp[i][j];
            if (mp[i][j] == '@') {
                x = i, y = j;
                mp[i][j] = '.';
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        char c;
        int v;
        cin >> c >> v;
        cost[c] = v;
    }
    dfs(x, y, 0, 0);
    cout << ans << '\n';
    return 0;
}