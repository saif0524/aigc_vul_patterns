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

#define MOD 100000007

struct Point {
    int x, y;
};

int main() {
    int r, c, a1, a2, b1, b2;
    cin >> r >> c >> a1 >> a2 >> b1 >> b2;

    vector<vector<long long>> dp(r, vector<long long>(c, 0));
    dp[a1][a2] = 1;

    queue<Point> q;
    q.push({a1, a2});
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    visited[a1][a2] = true;

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = current.x + dx[dir];
            int ny = current.y + dy[dir];

            if (nx < 0) nx = r - 1;
            if (ny < 0) ny = c - 1;
            if (nx >= r) nx = 0;
            if (ny >= c) ny = 0;

            if (!visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }

            dp[nx][ny] = (dp[nx][ny] + dp[current.x][current.y]) % MOD;
        }
    }

    cout << dp[b1][b2] << endl;
    return 0;
}