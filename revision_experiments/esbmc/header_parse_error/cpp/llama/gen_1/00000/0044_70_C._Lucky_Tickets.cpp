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

long long rev(long long x) {
    long long res = 0;
    while (x) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int maxx, maxy, w;
    cin >> maxx >> maxy >> w;
    long long ans = LLONG_MAX;
    int resx, resy;
    for (int x = 1; x <= maxx; x++) {
        for (int y = 1; y <= maxy; y++) {
            long long cnt = 0;
            for (int i = 1; i <= x; i++) {
                for (int j = 1; j <= y; j++) {
                    if (i * j == rev(i) * rev(j)) {
                        cnt++;
                    }
                }
            }
            if (cnt >= w && x * y < ans) {
                ans = x * y;
                resx = x;
                resy = y;
            }
        }
    }
    if (ans == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << resx << " " << resy << endl;
    }
    return 0;
}