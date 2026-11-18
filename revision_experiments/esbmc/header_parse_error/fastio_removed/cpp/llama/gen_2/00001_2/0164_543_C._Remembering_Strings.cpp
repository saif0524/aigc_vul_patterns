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

const int MAXN = 20;
const int MAXM = 20;

int n, m;
string s[MAXN];
int cost[MAXN][MAXM];
int dp[1 << MAXN];

int main() {
    ((void)0);
    ((void)0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cost[i][j];
        }
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        dp[mask] = 1e9;
    }
    dp[0] = 0;

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0) {
                int newMask = mask | (1 << i);
                for (int j = 0; j < m; j++) {
                    bool unique = true;
                    for (int k = 0; k < n; k++) {
                        if (k != i && s[k][j] == s[i][j]) {
                            unique = false;
                            break;
                        }
                    }
                    if (unique) {
                        dp[newMask] = min(dp[newMask], dp[mask]);
                        break;
                    }
                }
                if (dp[newMask] == 1e9) {
                    for (int j = 0; j < m; j++) {
                        dp[newMask] = min(dp[newMask], dp[mask] + cost[i][j]);
                    }
                }
            }
        }
    }

    cout << dp[(1 << n) - 1] << endl;

    return 0;
}