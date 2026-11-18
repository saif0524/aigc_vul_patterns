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

bool isEqual(double a, double b) {
    return abs(a - b) < 1e-9;
}

int main(){
    ((void)0);
    ((void)0);
    double ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    double midx = (ax + cx) / 2.0;
    double midy = (ay + cy) / 2.0;
    double dx = bx - midx;
    double dy = by - midy;
    double len1 = sqrt(dx*dx + dy*dy);
    double ex = ax - midx;
    double ey = ay - midy;
    double len2 = sqrt(ex*ex + ey*ey);
    if(isEqual(len1, len2)){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}