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
};

double crossProduct(Point A, Point B, Point C) {
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        Point A, B, C, D;
        cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
        if (cin.fail()) break;
        
        double cross1 = crossProduct(A, B, C);
        double cross2 = crossProduct(B, C, D);
        double cross3 = crossProduct(C, D, A);
        double cross4 = crossProduct(D, A, B);
        
        bool convex = (cross1 >=0&& cross2 >=0&& cross3 >=0&& cross4 >= 0) ||
                     (cross1 <=0&& cross2 <=0&& cross3 <=0&& cross4 <= 0);
        
        cout << (convex ? "YES" : "NO") << "\n";
    }
    return 0;
}