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

int n, m;
vector<int> a;

void solve() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cin >> m;
    while (m--) {
        int k, pos;
        cin >> k >> pos;
        --pos;

        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        vector<vector<pair<int, int>>> prev(k + 1, vector<pair<int, int>>(n + 1, {-1, -1}));

        dp[0][0] = 0;
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] != -1) {
                    for (int idx = j; idx < n; ++idx) {
                        if (dp[i + 1][idx + 1] == -1 || 
                            dp[i][j] + a[idx] > dp[i + 1][idx + 1] || 
                            (dp[i][j] + a[idx] == dp[i + 1][idx + 1] && 
                             a[idx] < a[prev[i + 1][idx + 1].first])) {
                            dp[i + 1][idx + 1] = dp[i][j] + a[idx];
                            prev[i + 1][idx + 1] = {idx, a[idx]};
                        }
                    }
                }
            }
        }

        vector<int> res;
        int curr = k, idx = n;
        while (curr) {
            while (dp[curr][idx] == -1) --idx;
            res.push_back(prev[curr][idx].second);
            idx = prev[curr][idx].first;
            --curr;
        }

        reverse(res.begin(), res.end());
        cout << res[pos - 1] << '\n';
    }
}

int main() {
    ((void)0);
    ((void)0);
    ((void)0);

    solve();
    return 0;
}