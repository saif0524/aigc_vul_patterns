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

typedef long long ll;

const int maxn = 5e5 + 10;

int n;
ll a[maxn];

ll dp[maxn][2];

ll min(ll a, ll b) {
    return a < b ? a : b;
}

ll max(ll a, ll b) {
    return a > b ? a : b;
}

ll rec(int i, int j) {
    if (i == j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    ll ans = a[i + 1] < a[i] ? rec(i + 1, j) : a[i + 1] > a[i] ? rec(i, j - 1) : max(rec(i + 1, j), rec(i, j - 1));
    ans = max(ans, max(min(a[i - 1], a[i]) + rec(i + 1, j), min(a[j], a[j + 1]) + rec(i, j - 1)));
    return dp[i][j] = ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(1, n) << endl;
    return 0;
}