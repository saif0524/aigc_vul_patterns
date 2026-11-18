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
typedef double db;

const int MAXN = 55;
const db EPS = 1e-8;

int N;
db X[MAXN], Y[MAXN];

struct Point {
    db x, y;
    Point(db _x = 0, db _y = 0) : x(_x), y(_y) {}
    Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
    db cross(const Point &p) const { return x * p.y - y * p.x; }
};

db polygon_area() {
    db area = 0;
    for(int i = 0; i < N; i++) {
        int j = (i + 1) % N;
        area += X[i] * Y[j] - X[j] * Y[i];
    }
    return fabs(area) / 2;
}

bool find_centroid(db &cx, db &cy) {
    db total_area = polygon_area();
    if(total_area == 0) return false;
    db area = 0;
    cx = cy = 0;
    for(int i = 0; i < N; i++) {
        int j = (i + 1) % N;
        Point a(X[i], Y[i]), b(X[j], Y[j]);
        db cross_product = a.cross(b);
        area += cross_product;
        cx += (a.x + b.x) * cross_product;
        cy += (a.y + b.y) * cross_product;
    }
    area /= 2;
    cx /= 6 * area;
    cy /= 6 * area;
    return true;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> X[i] >> Y[i];
    
    db cx, cy;
    if(!find_centroid(cx, cy)) {
        cout << "NA" << endl;
        return 0;
    }
    
    printf("%.5f %.5f\n", cx, cy);
}