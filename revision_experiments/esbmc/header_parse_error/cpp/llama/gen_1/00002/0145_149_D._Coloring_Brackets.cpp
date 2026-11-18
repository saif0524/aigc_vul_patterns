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
const int MOD = 1000000007;

int dp[1005][1005];
string s;

int recur(int i, int j) {
    if (i >= s.size()) return 1;
    if (dp[i][j] != -1) return dp[i][j];
    int ans = 0;
    if (s[i] == '(') {
        if (j == 0) {
            ans = (ans + recur(i + 1, 1)) % MOD;
        } else {
            ans = (ans + recur(i + 1, 0)) % MOD;
        }
    } else {
        if (j == 0) {
            ans = (ans + 2 * recur(i + 1, 1)) % MOD;
        } else {
            ans = (ans + 2 * recur(i + 1, 0)) % MOD;
        }
    }
    return dp[i][j] = ans;
}

int main() {
    cin >> s;
    memset(dp, -1, sizeof dp);
    cout << recur(0, 0) << endl;
    return 0;
}