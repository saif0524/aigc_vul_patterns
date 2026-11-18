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

#define MAX_A 10000
#define MAX_B 30

int a, b, n;
int cache[MAX_A + 1][MAX_B + 1];

int pow(int x, int e) {
    if (e == 0) return 1;
    if (e % 2 == 1) return x * pow(x, e - 1);
    return pow(x * x, e / 2);
}

bool win(int a, int b) {
    if (cache[a][b] != 0) return cache[a][b] == 1;

    bool result = !(
        (!win(a + 1, b) || b == 1 && !win(a, b + 1))
        && (b > 1 && !win(a, b + 1) || !win(a + 1, b))
    );

    cache[a][b] = result ? 1 : -1;
    return result;
}

void solve() {
    std::cin >> a >> b >> n;

    if (pow(a, b) >= n) {
        std::cout << "Missing" << std::endl;
        return;
    }

    if (win(a, b)) {
        std::cout << "Stas" << std::endl;
    } else {
        std::cout << "Masha" << std::endl;
    }
}

int main() {
    ((void)0);
    ((void)0);

    solve();

    return 0;
}