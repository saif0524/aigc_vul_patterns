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
const ld PI = acosl(-1.L);
const ld EPS = 1e-9;

ld get_angle(ld x1, ld y1, ld x2, ld y2) {
    ld angle = atan2l(y2 - y1, x2 - x1);
    return angle < 0 ? angle + 2 * PI : angle;
}

bool can(ld v, ld ax, ld ay, ld bx, ld by, ld ex, ld ey, ld theta, ld omega, ld k) {
    ld vx = bx - ax;
    ld vy = by - ay;
    ld dist = hypotl(vx, vy);
    vx /= dist;
    vy /= dist;

    ld angle_pedal = get_angle(ax, ay, ex, ey);
    ld angle_target = get_angle(ex, ey, bx, by);

    ld delta = fmodl(angle_target - angle_pedal + 2 * PI, 2 * PI);
    if (delta > PI) {
        delta = 2 * PI - delta;
    }
    ld time_to_turn = delta / omega;
    ld time_to_reach = hypotl(ex - ax, ey - ay) / v;

    if (time_to_turn <= time_to_reach + EPS) {
        k--;
    }
    return k >= 0;
}

bool check(ld v, ld ax, ld ay, ld bx, ld by, vector<tuple<ld, ld, ld, ld>>& tanks, ld k) {
    for (auto &[ex, ey, theta, omega] : tanks) {
        if (can(v, ax, ay, bx, by, ex, ey, theta, omega, k)) {
            continue;
        }
        return false;
    }
    return true;
}

int main(){
    ((void)0);
    ((void)0);

    ld ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    int n;
    cin >> n;
    vector<tuple<ld, ld, ld, ld>> tanks(n);
    for (auto& [x, y, a, w] : tanks) {
        cin >> x >> y >> a >> w;
    }
    ld k;
    cin >> k;

    ld lo = 0, hi = 1e5;
    while (hi - lo > EPS) {
        ld mid = (lo + hi) / 2;
        if (check(mid, ax, ay, bx, by, tanks, k)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << fixed << setprecision(4) << lo;
}