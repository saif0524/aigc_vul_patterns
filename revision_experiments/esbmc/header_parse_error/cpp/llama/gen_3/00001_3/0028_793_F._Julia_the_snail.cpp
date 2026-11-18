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

const int MAXN = 100005;

int n, m, q;
int ropes[MAXN];
int dp[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        ropes[r] = max(ropes[r], l);
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = i;
        for (int j = i; j <= n; j++) {
            if (ropes[j] >= i) {
                dp[i] = max(dp[i], j);
            }
        }
    }

    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        int ans = x;
        for (int i = x; i <= y; i++) {
            if (dp[i] <= y) {
                ans = max(ans, dp[i]);
            }
        }
        cout << ans << "\n";
    }

    return 0;
}