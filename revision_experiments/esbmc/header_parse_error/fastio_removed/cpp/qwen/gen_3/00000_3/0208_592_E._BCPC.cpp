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

struct Point {
    ll x, y;
    Point() : x(0), y(0) {}
    Point(ll x, ll y) : x(x), y(y) {}
    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

ll cross(const Point& O, const Point& A, const Point& B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

int main(){
    ((void)0);
    ((void)0);
    int n;
    ll c, d;
    cin >> n >> c >> d;
    vector<Point> points(n);
    for(int i = 0; i < n; ++i){
        ll r, w;
        cin >> r >> w;
        points[i] = Point(r - c, w - d);
    }
    sort(points.begin(), points.end());
    vector<Point> hull;
    for(int i = 0; i < n; ++i){
        while(hull.size() >= 2 && cross(hull[hull.size()-2], hull.back(), points[i]) <= 0){
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    int m = hull.size();
    ll res = 0;
    for(int i = 0; i < m; ++i){
        for(int j = i + 1; j < m; ++j){
            for(int k = j + 1; k < m; ++k){
                if(cross(hull[i], hull[j], hull[k]) < 0){
                    res++;
                }
            }
        }
    }
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < i; ++j){
            for(int k = 0; k < j; ++k){
                if(cross(hull[i], hull[j], hull[k]) < 0){
                    res++;
                }
            }
        }
    }
    cout << res;
}