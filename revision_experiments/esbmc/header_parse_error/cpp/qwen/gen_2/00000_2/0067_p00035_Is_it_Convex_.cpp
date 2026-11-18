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

double cross_product(double x1, double y1, double x2, double y2) {
    return x1 * y2 - x2 * y1;
}

bool is_convex(double xa, double ya, double xb, double yb, double xc, double yc, double xd, double yd) {
    double cp1 = cross_product(xb - xa, yb - ya, xc - xb, yc - yb);
    double cp2 = cross_product(xc - xb, yc - yb, xd - xc, yd - yc);
    double cp3 = cross_product(xd - xc, yd - yc, xa - xd, ya - yd);
    double cp4 = cross_product(xa - xd, ya - yd, xb - xa, yb - ya);
    
    return (cp1 > 0 && cp2 > 0 && cp3 > 0 && cp4 > 0) || (cp1 < 0 && cp2 < 0 && cp3 < 0 && cp4 < 0);
}

int main() {
    double xa, ya, xb, yb, xc, yc, xd, yd;
    while (cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd) {
        if (is_convex(xa, ya, xb, yb, xc, yc, xd, yd)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}