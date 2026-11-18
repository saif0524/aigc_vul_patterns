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

const int MAXN = 300005;
const int MAXBITS = 20;

int n, q;
int a[MAXN];
bool dp[MAXN][MAXBITS];

int main() {
    ((void)0);
    ((void)0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < MAXBITS; j++) {
            if ((a[i] >> j) & 1) {
                dp[i][j] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < MAXBITS; j++) {
            if (dp[i][j]) {
                for (int k = i + 1; k <= n; k++) {
                    if ((a[k] >> j) & 1) {
                        for (int l = 0; l < MAXBITS; l++) {
                            dp[k][l] = dp[k][l] || dp[i][l];
                        }
                    }
                }
            }
        }
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        bool reachable = false;
        for (int i = 0; i < MAXBITS; i++) {
            if (dp[y][i] && ((a[x] >> i) & 1)) {
                reachable = true;
                break;
            }
        }
        cout << (reachable ? "Shi" : "Fou") << '\n';
    }

    return 0;
}