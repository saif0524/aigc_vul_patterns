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

int f(string s) {
    string t = s;
    sort(t.begin(), t.end());
    while (!t.empty() && t[0] == '0') t.erase(t.begin());
    return t.empty() ? 0 : stoi(t);
}

int main() {
    ((void)0);
    ((void)0);
    long long l, r;
    cin >> l >> r;
    set<long long> ss;
    for (long long i = l; i <= r; i++) {
        ss.insert(f(to_string(i)));
    }
    cout << ss.size() << '\n';
    return 0;
}