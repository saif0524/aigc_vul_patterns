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

int rev(int x) {
    int res = 0;
    while (x > 0) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

bool isLucky(int a, int b) {
    return a * b == rev(a) * rev(b);
}

int main() {
    int maxx, maxy, w;
    cin >> maxx >> maxy >> w;
    int count = 0;
    for (int x = 1; x <= maxx && count < w; ++x) {
        for (int y = 1; y <= maxy && count < w; ++y) {
            for (int a = 1; a <= x && count < w; ++a) {
                for (int b = 1; b <= y && count < w; ++b) {
                    if (isLucky(a, b)) {
                        count++;
                    }
                }
            }
            if (count >= w) {
                cout << x << " " << y;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}