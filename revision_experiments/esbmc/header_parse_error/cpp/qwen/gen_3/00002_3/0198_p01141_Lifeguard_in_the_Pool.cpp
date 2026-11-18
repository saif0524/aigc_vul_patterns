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

struct Point {
    double x, y;
    Point() : x(0), y(0) {}
    Point(double _x, double _y) : x(_x), y(_y) {}
};

double distance(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double solve(int n, const vector<Point>& pool, double tg, double tw, const Point& guard, const Point& girl) {
    double best = 1e18;
    for (int i = 0; i < n; ++i) {
        Point p1 = pool[i];
        Point p2 = pool[(i + 1) % n];
        for (double t = 0; t <= 1; t += 0.01) {
            Point p = {p1.x + t * (p2.x - p1.x), p1.y + t * (p2.y - p1.y)};
            double d1 = distance(guard, p);
            double d2 = distance(p, girl);
            best = min(best, d1 * tg + d2 * tw);
        }
    }
    return best;
}

int main(){
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;
        vector<Point> pool(n);
        for(int i = 0; i < n; ++i){
            cin >> pool[i].x >> pool[i].y;
        }
        double tg, tw;
        cin >> tg >> tw;
        Point guard, girl;
        cin >> guard.x >> guard.y >> girl.x >> girl.y;
        cout << fixed << setprecision(10) << solve(n, pool, tg, tw, guard, girl) << '\n';
    }
}