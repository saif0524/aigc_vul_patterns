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

unordered_map<long long, int> memo;

int findMaxProductSteps(long long n) {
    if (n < 10) return 0;
    if (memo.find(n) != memo.end()) return memo[n];
    string s = to_string(n);
    int maxSteps = -1;
    for (int i = 1; i < s.size(); ++i) {
        long long left = stoll(s.substr(0, i));
        long long right = stoll(s.substr(i));
        if (left == 0 || right == 0) continue;
        int steps = findMaxProductSteps(left * right);
        if (steps != -1) {
            if (maxSteps == -1 || steps + 1 > maxSteps) {
                maxSteps = steps + 1;
            }
        }
    }
    return memo[n] = maxSteps;
}

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        long long n;
        cin >> n;
        cout << findMaxProductSteps(n) << "\n";
    }
}