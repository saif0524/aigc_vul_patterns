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

int main() {
    int N;
    cin >> N;
    vector<int> P(N * N);
    for (int i = 0; i < N * N; ++i) {
        cin >> P[i];
    }
    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            grid[i][j] = (i * N) + j + 1;
        }
    }
    vector<pair<int, int>> positions(N * N + 1);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            positions[grid[i][j]] = {i, j};
        }
    }
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    int ans = 0;
    for (int p : P) {
        auto [x, y] = positions[p];
        for (const auto& dir : directions) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            while (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny]) {
                ans++;
                nx += dir[0];
                ny += dir[1];
            }
        }
        visited[x][y] = true;
    }
    cout << ans;
}