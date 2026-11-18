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

double calcArea(double a, double l, double x) {
    double s = (a + l + l + x) / 2.0;
    double areaABC = sqrt(s * (s - a) * (s - l) * (s - l));

    double s1 = (a + l + (l + x) / 2.0) / 2.0;
    double areaADC = sqrt(s1 * (s1 - a) * (s1 - l) * (s1 - (l + x) / 2.0));

    double s2 = (a + (l + x) / 2.0 + l) / 2.0;
    double areaBEC = sqrt(s2 * (s2 - a) * (s2 - (l + x) / 2.0) * (s2 - l));

    return areaABC + areaADC + areaBEC;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, l, x;
    while(cin >> a >> l >> x){
        double maxArea = 0.0;
        for(double i = 0.0; i <= x; i += 0.0001){
            double area = calcArea(a, l, i) + calcArea(a, l, x - i);
            maxArea = max(maxArea, area);
        }
        cout << fixed << setprecision(10) << maxArea << "\n";
    }
}