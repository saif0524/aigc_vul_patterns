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
};

ll orientation(Point p, Point q, Point r) {
    ll val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

bool isInsidePolygon(Point polygon[], int n, Point p) {
    if (n < 3) return false;
    Point extreme = {1e10, p.y};
    int count = 0;
    int i = 0;
    do {
        int next = (i + 1) % n;
        if (orientation(polygon[i], polygon[next], p) == 0) {
            if (p.x <= max(polygon[i].x, polygon[next].x) && p.x >= min(polygon[i].x, polygon[next].x) &&
                p.y <= max(polygon[i].y, polygon[next].y) && p.y >= min(polygon[i].y, polygon[next].y)) {
                return true;
            }
            return false;
        }
        if (orientation(polygon[i], p, extreme) == 2) {
            int o2 = orientation(polygon[next], p, extreme);
            if (o2 == 1) count++;
        } else {
            int o2 = orientation(polygon[next], p, extreme);
            if (o2 == 2) count++;
        }
        i = next;
    } while (i != 0);
    return count & 1;
}

int main(){
    ((void)0);
    ((void)0);
    int n;
    cin >> n;
    Point points[n];
    for(int i=0;i<n;i++) cin >> points[i].x >> points[i].y;
    Point A = points[0], B = points[1];
    int ans=0;
    for(ll x=min(A.x,B.x);x<=max(A.x,B.x);x++){
        Point p = {x, A.y};
        if(!isInsidePolygon(points, n, p)) ans++;
    }
    cout << ans;
}