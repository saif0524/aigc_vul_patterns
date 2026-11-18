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

int n, r;
vector<long long> f;

double minimax(int mask, int turn, vector<vector<double>> &memo) {
    if (mask == (1 << n) - 1) {
        return f[mask];
    }
    if (memo[mask][turn] != -1) return memo[mask][turn];
    double res = (turn == 0) ? -1e18 : 1e18;
    for (int i = 0; i < n; ++i) {
        if ((mask & (1 << i)) == 0) {
            int new_mask = mask | (1 << i);
            double val = minimax(new_mask, 1 - turn, memo);
            if (turn == 0) res = max(res, val);
            else res = min(res, val);
        }
    }
    return memo[mask][turn] = res;
}

int main() {
    ((void)0);
    ((void)0);
    cin >> n >> r;
    f.resize(1 << n);
    for (auto &x : f) cin >> x;
    vector<vector<double>> memo(1 << n, vector<double>(2, -1));
    cout << fixed << setprecision(6);
    cout << minimax(0, 0, memo) << "\n";
    for (int i = 0; i < r; ++i) {
        int z, g;
        cin >> z >> g;
        f[z] = g;
        fill(memo.begin(), memo.end(), vector<double>(2, -1));
        cout << minimax(0, 0, memo) << "\n";
    }
}