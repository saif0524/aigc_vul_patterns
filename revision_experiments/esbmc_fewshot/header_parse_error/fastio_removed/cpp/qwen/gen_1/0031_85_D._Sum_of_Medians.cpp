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

multiset<long long> s;

long long findMedian() {
    int n = s.size();
    if (n ==0) return 0;
    auto it = s.begin();
    advance(it, n / 2);
    return *it;
}

long long sumOfMedians() {
    long long sum = 0;
    int n = s.size();
    if (n ==0) return 0;
    vector<long long> v(s.begin(), s.end());
    for (int i = 0; i < n; i += 5) {
        if (i + 4 < n) {
            nth_element(v.begin() + i, v.begin() + i + 2, v.begin() + i + 5);
            sum += v[i +2];
        } else if (i + 3 < n) {
            nth_element(v.begin() + i, v.begin() + i + 1, v.begin() + i + 4);
            sum += v[i +1];
        } else if (i + 2 < n) {
            nth_element(v.begin() + i, v.begin() + i + 1, v.begin() + i + 3);
            sum += v[i +1];
        } else if (i + 1 < n) {
            nth_element(v.begin() + i, v.begin() + i + 1, v.begin() + i + 2);
            sum += v[i +1];
        } else {
            sum += v[i];
        }
    }
    return sum;
}

int main() {
    ((void)0);
    ((void)0);
    int n;
    cin >> n;
    while (n--) {
        string op;
        cin >> op;
        if (op == "add") {
            long long x;
            cin >> x;
            s.insert(x);
        } else if (op == "del") {
            long long x;
            cin >> x;
            s.erase(s.find(x));
        } else if (op == "sum") {
            cout << sumOfMedians() << "\n";
        }
    }
    return 0;
}