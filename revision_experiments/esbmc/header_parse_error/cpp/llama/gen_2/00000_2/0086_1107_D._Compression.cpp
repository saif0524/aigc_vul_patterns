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

int n;
string s[5205];
char a[5205][5205];

bool check(int x) {
    for (int i = 0; i < n; i += x) {
        for (int j = 0; j < n; j += x) {
            char val = a[i][j];
            for (int p = i; p < i + x; p++) {
                for (int q = j; q < j + x; q++) {
                    if (a[p][q] != val) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 4; j++) {
            int val = s[i][j] - '0';
            if (val > 9) {
                val -= 7;
            }
            for (int k = 0; k < 4; k++) {
                a[i][j * 4 + k] = (val >> (3 - k)) & 1 ? '1' : '0';
            }
        }
    }
    int ans = 1;
    for (int x = 2; x <= n; x++) {
        if (n % x == 0 && check(x)) {
            ans = x;
        }
    }
    cout << ans << endl;
    return 0;
}