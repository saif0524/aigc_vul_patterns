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

int countSets(int n, int k, int s) {
    if (k == 0) return (s == 0) ? 1 : 0;
    if (n ==0) return 0;
    int count = countSets(n - 1, k, s);
    if (s >= n) count += countSets(n -1, k - 1, s - n);
    return count;
}

int main() {
    ((void)0);
    ((void)0);
    int n, k, s;
    while (cin >> n >> k >> s) {
        if (n ==0&& k == 0 && s == 0) break;
        cout << countSets(n, k, s) << "\n";
    }
    return 0;
}