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

typedef long double ld;

int main(){
    ((void)0);
    ((void)0);
    ld k, d, t;
    cin >> k >> d >> t;
    ld total_time = 0;
    ld time_cooked = 0;
    while (time_cooked < t) {
        if (time_cooked + d <= t) {
            if (time_cooked + k < time_cooked + d) {
                ld cooking_time = k;
                time_cooked += cooking_time;
                total_time += cooking_time;
            } else {
                ld cooking_time = d - time_cooked;
                time_cooked += cooking_time;
                total_time += cooking_time;
            }
        } else {
            ld remaining_time = t - time_cooked;
            if (remaining_time <= k) {
                total_time += remaining_time;
            } else {
                total_time += 2 * remaining_time;
            }
            break;
        }
        ld remaining_d = d - (total_time - ld(floor(total_time / d)) * d);
        if (remaining_d < k) {
            ld sleep_time = min(remaining_d, k);
            ld cooking_off_time = sleep_time;
            total_time += cooking_off_time;
        } else {
            total_time += 2 * k;
        }
    }
    cout << fixed << setprecision(10) << total_time << "\n";
}