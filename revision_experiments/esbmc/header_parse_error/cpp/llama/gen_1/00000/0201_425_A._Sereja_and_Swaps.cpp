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

const int INF = 1e9;

int n, k;
int a[200];
int memo[201][11];

int dp(int i, int j) {
    if (i == n) return 0;
    if (j == k) return 0;
    if (memo[i][j] != -1) return memo[i][j];

    int ans = dp(i + 1, j);
    for (int l = i + 1; l < n; l++) {
        int tmp = a[i];
        a[i] = a[l];
        a[l] = tmp;
        ans = max(ans, a[i] + dp(i + 1, j + 1));
        tmp = a[i];
        a[i] = a[l];
        a[l] = tmp;
    }
    memo[i][j] = ans;
    return ans;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memset(memo, -1, sizeof memo);
    cout << dp(0, 0) << endl;
    return 0;
}