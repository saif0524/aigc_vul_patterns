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

double max_val;

void calculate(vector<double> &vals, int depth, int n) {
    if (depth == n - 1) {
        max_val = max(max_val, vals[0]);
    } else {
        for (int i = 0; i < vals.size() - 1; i++) {
            for (int j = i + 1; j < vals.size(); j++) {
                double new_val = (vals[i] + vals[j]) / 2.0;
                vector<double> new_vals;
                for (int k = 0; k < vals.size(); k++) {
                    if (k != i && k != j) {
                        new_vals.push_back(vals[k]);
                    }
                }
                new_vals.push_back(new_val);
                calculate(new_vals, depth + 1, n);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<double> vals(n);
    for (int i = 0; i < n; i++) {
        cin >> vals[i];
    }
    max_val = -1e9;
    calculate(vals, 0, n);
    printf("%.5f\n", max_val);
    return 0;
}