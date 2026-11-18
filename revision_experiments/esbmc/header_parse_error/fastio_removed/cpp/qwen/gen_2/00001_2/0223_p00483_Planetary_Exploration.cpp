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
    ((void)0);
    ((void)0);
    int M, N, K;
    cin >> M >> N >> K;
    vector<vector<char>> grid(M, vector<char>(N));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }
    vector<vector<vector<int>>> prefix_sum(M + 1, vector<vector<int>>(N + 1, vector<int>(3)));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            prefix_sum[i + 1][j + 1][0] = prefix_sum[i][j + 1][0] + prefix_sum[i + 1][j][0] - prefix_sum[i][j][0] + (grid[i][j] == 'J');
            prefix_sum[i + 1][j + 1][1] = prefix_sum[i][j + 1][1] + prefix_sum[i + 1][j][1] - prefix_sum[i][j][1] + (grid[i][j] == 'O');
            prefix_sum[i + 1][j + 1][2] = prefix_sum[i][j + 1][2] + prefix_sum[i + 1][j][2] - prefix_sum[i][j][2] + (grid[i][j] == 'I');
        }
    }
    for (int k = 0; k < K; ++k) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int j = prefix_sum[c][d][0] - prefix_sum[a-1][d][0] - prefix_sum[c][b-1][0] + prefix_sum[a-1][b-1][0];
        int o = prefix_sum[c][d][1] - prefix_sum[a-1][d][1] - prefix_sum[c][b-1][1] + prefix_sum[a-1][b-1][1];
        int i = prefix_sum[c][d][2] - prefix_sum[a-1][d][2] - prefix_sum[c][b-1][2] + prefix_sum[a-1][b-1][2];
        cout << j << " " << o << " " << i << "\n";
    }
    return 0;
}