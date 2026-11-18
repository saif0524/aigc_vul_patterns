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

bool isLucky(int x) {
    while (x > 0) {
        int d = x % 10;
        if (d != 4 && d != 7) return false;
        x /= 10;
    }
    return true;
}

int main() {
    long long n, k;
    cin >> n >> k;
    long long fact = 1;
    for (long long i = 2; i <= n; ++i) {
        fact *= i;
        if (fact > 1e9) {
            cout << "-1";
            return 0;
        }
    }
    if (k > fact) {
        cout << "-1";
        return 0;
    }
    vector<int> perm(n);
    for (int i = 0; i < n; ++i) perm[i] = i + 1;
    for (long long i = 0; i < k - 1; ++i) next_permutation(perm.begin(), perm.end());
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (isLucky(i + 1) && isLucky(perm[i])) ++count;
    }
    cout << count;
}