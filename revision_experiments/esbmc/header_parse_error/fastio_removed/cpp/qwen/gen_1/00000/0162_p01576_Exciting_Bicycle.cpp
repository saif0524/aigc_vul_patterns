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

const ld g = 9.8;

ld distance(ld x1, ld y1, ld x2, ld y2) {
    return sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main(){
    ((void)0);
    ((void)0);
    int N, V;
    cin >> N >> V;
    vector<pair<ld, ld>> points(N);
    for(int i = 0; i < N; i++){
        cin >> points[i].first >> points[i].second;
    }
    ld total_distance = 0.0;
    for(int i = 1; i < N; i++){
        ld x1 = points[i-1].first, y1 = points[i-1].second;
        ld x2 = points[i].first, y2 = points[i].second;
        ld dx = x2 - x1, dy = y2 - y1;
        ld tan_prev = (i == 1) ? 1e9 : (points[i-1].second - points[i-2].second) / (points[i-1].first - points[i-2].first);
        ld tan_curr = dy / dx;
        if(i == 1 || tan_curr < tan_prev){
            ld t_jump = (V / g) * (tan_curr + sqrtl(tan_curr * tan_curr + (2 * g * dy) / (V * V)));
            ld x_fall = x1 + V * t_jump - 0.5 * g * t_jump * t_jump / tan_curr;
            total_distance += distance(x1, y1, x_fall, y2);
        } else {
            total_distance += distance(x1, y1, x2, y2);
        }
    }
    cout << fixed << setprecision(10) << total_distance << endl;
}