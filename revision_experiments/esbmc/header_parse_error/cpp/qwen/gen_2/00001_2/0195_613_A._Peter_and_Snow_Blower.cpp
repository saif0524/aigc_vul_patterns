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
typedef pair<ll, ll> pll;

ll cross(pll a, pll b) {
    return a.first * b.second - a.second * b.first;
}

double polygonArea(vector<pll>& points) {
    int n = points.size();
    double area = 0.0;
    for (int i = 0; i < n; ++i) {
        area += cross(points[i], points[(i + 1) % n]);
    }
    return fabs(area) / 2.0;
}

double distance(pll a, pll b) {
    ll dx = a.first - b.first;
    ll dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    int n;
    pll P;
    cin >> n >> P.first >> P.second;
    vector<pll> polygon(n);
    for (auto& p : polygon) {
        cin >> p.first >> p.second;
    }
    
    double minRadius = INFINITY;
    for (const auto& p : polygon) {
        minRadius = min(minRadius, distance(P, p));
    }
    
    double area = polygonArea(polygon);
    double totalArea = area + M_PI * minRadius * minRadius;
    
    cout << fixed << setprecision(15) << totalArea << endl;
    
    return 0;
}