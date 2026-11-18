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

const int MOD = 1e9 + 7;

long long power(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    long long ans = 0;

    for (int a = 0; a < n; ++a) {
        for (int b = a + k - 1; b < n; ++b) {
            for (int c = b + 1; c < n; ++c) {
                for (int d = c + k - 1; d < n; ++d) {
                    if (d - c + 1 != k) continue;
                    if (b - a + 1 != k) continue;

                    string t = s;
                    bool flag = true;
                    for (int i = a; i <= b; ++i) {
                        if (t[i] == 'W') flag = false;
                        t[i] = 'B';
                    }
                    for (int i = c; i <= d; ++i) {
                        if (t[i] == 'B') flag = false;
                        t[i] = 'W';
                    }
                    if (flag) ++ans;
                }
            }
        }
    }

    cout << ans % MOD << '\n';

    return 0;
}