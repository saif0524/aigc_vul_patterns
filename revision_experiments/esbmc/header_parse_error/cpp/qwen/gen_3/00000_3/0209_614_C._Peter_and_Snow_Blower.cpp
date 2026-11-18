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

const ld PI = acos(-1.0);

struct Point {
    ld x, y;
};

ld distance(const Point& a, const Point& b) {
    return hypot(a.x - b.x, a.y - b.y);
}

ld polygonArea(vector<Point>& points) {
    int n = points.size();
    ld area = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += points[i].x * points[j].y;
        area -= points[j].x * points[i].y;
    }
    area = fabs(area) / 2.0;
    return area;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    Point P;
    cin >> n >> P.x >> P.y;
    vector<Point> polygon(n);
    for(auto &p: polygon){
        cin >> p.x >> p.y;
    }
    ld radius = 0;
    for(const auto &p: polygon){
        radius = max(radius, distance(p, P));
    }
    ld polygonAreaValue = polygonArea(polygon);
    ld totalArea = polygonAreaValue + 2 * PI * radius * radius;
    cout << fixed << setprecision(16) << totalArea << "\n";
}