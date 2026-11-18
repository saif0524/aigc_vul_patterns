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

int main() {
    ((void)0);
    ((void)0);

    int n;
    cin >> n;

    vector<int> factors;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i != 0) continue;
        factors.push_back(i);
        if (i * i != n) factors.push_back(n / i);
    }
    if (factors.empty()) {
        cout << 0 << '\n';
        return 0;
    }

    sort(factors.begin(), factors.end());
    factors.erase(unique(factors.begin(), factors.end()), factors.end());

    long long ans = 0;
    for (int fac : factors) {
        ans += fac;
        if (fac != n / fac) {
            ans += n / fac;
        }
    }

    cout << 2 * ans << '\n';

    return 0;
}