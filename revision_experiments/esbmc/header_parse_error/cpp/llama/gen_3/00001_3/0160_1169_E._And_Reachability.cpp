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
int arr[MAXN];

bool dp[MAXN][MAXBITS];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        for (int j = 0; j < MAXBITS; j++) {
            if (arr[i] & (1 << j)) {
                dp[i][j] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                continue;
            }
            for (int k = 0; k < MAXBITS; k++) {
                if (dp[i][k] && dp[j][k]) {
                    dp[j][k] = true;
                    for (int l = 0; l < MAXBITS; l++) {
                        if (arr[j] & (1 << l)) {
                            dp[j][l] = dp[j][l] || dp[i][l];
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        bool reachable = false;
        for (int j = 0; j < MAXBITS; j++) {
            if (dp[y][j] && arr[x] & (1 << j)) {
                reachable = true;
                break;
            }
        }
        cout << (reachable ? "Shi" : "Fou") << endl;
    }

    return 0;
}