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
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> weights;
    for (char c : s) {
        weights.push_back(c - 'a' + 1);
    }
    sort(weights.begin(), weights.end());
    int result = INT_MAX;
    bool found = false;
    for (int i = 0; i < (1 << n); ++i) {
        int count = 0;
        int sum = 0;
        int last = -2;
        bool valid = true;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                if (weights[j] <= last + 1) {
                    valid = false;
                    break;
                }
                last = weights[j];
                sum += weights[j];
                count++;
            }
        }
        if (valid && count == k) {
            result = min(result, sum);
            found = true;
        }
    }
    if (found) {
        cout << result << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}