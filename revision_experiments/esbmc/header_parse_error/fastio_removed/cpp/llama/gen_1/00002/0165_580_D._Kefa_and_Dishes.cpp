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
#define int long long
#define endl '\n'
const int mod = 1e9 + 7;

struct Edge {
    int to, weight;
};

struct Rule {
    int x, y, c;
};

int dp[1 << 18][18];
int n, m, k;
int a[18];
vector<Rule> rules;

int get_mask(vector<int> v) {
    int mask = 0;
    for (int x : v) {
        mask |= (1 << x);
    }
    return mask;
}

int solve(int mask, int last) {
    if (__builtin_popcount(mask) == m) {
        return 0;
    }

    if (dp[mask][last] != -1) {
        return dp[mask][last];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i))) {
            int add = a[i];
            if (last != -1) {
                for (auto r : rules) {
                    if (r.x == last && r.y == i) {
                        add += r.c;
                        break;
                    }
                }
            }

            ans = max(ans, add + solve(mask | (1 << i), i));
        }
    }

    return dp[mask][last] = ans;
}

signed main() {
    ((void)0);
    ((void)0);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < k; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        x--, y--;
        rules.push_back({x, y, c});
    }

    memset(dp, -1, sizeof dp);

    cout << solve(0, -1) << endl;
}