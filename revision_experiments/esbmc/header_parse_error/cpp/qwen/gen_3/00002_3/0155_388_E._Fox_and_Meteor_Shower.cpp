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

typedef long long ll;

struct Meteor {
    ll t1, x1, y1, t2, x2, y2;
    pair<ll, ll> compute(ll t) {
        ll dx = x2 - x1, dy = y2 - y1, dt = t2 - t1;
        ll nx = x1 + dx * (t - t1) / dt;
        ll ny = y1 + dy * (t - t1) / dt;
        return {nx, ny};
    }
};

bool isCollinear(ll a1, ll b1, ll a2, ll b2, ll a3, ll b3) {
    return (b2 - b1) * (a3 - a1) == (b3 - b1) * (a2 - a1);
}

int main() {
    int n;
    cin >> n;
    vector<Meteor> meteors(n);
    for (auto &m : meteors) {
        cin >> m.t1 >> m.x1 >> m.y1 >> m.t2 >> m.x2 >> m.y2;
    }

    int max_meteors = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ll a1 = meteors[i].x1, b1 = meteors[i].y1;
            ll a2 = meteors[j].x1, b2 = meteors[j].y1;
            ll a3 = meteors[i].x2, b3 = meteors[i].y2;

            int count = 0;
            for (int k = 0; k < n; ++k) {
                ll x, y;
                if (meteors[k].t1 == meteors[k].t2) {
                    x = meteors[k].x1;
                    y = meteors[k].y1;
                } else {
                    ll dt12 = meteors[j].t2 - meteors[j].t1;
                    ll dt1k = meteors[k].t1 - meteors[j].t1;
                    ll t = meteors[j].t1 + dt1k * (meteors[i].t2 - meteors[i].t1) / (meteors[i].x2 - meteors[i].x1 - meteors[j].x2 + meteors[j].x1);
                    auto p = meteors[k].compute(t);
                    x = p.first;
                    y = p.second;
                }
                if (isCollinear(a1, b1, a2, b2, x, y)) {
                    count++;
                }
            }
            max_meteors = max(max_meteors, count);
        }
    }

    cout << max_meteors << "\n";
}