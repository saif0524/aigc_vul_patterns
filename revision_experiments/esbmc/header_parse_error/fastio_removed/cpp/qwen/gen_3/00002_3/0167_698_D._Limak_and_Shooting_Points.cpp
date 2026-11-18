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

typedef pair<long long, long long> Point;

bool canHit(const Point& p1, const Point& p2, const Point& p3) {
    long long A = p2.second - p1.second;
    long long B = p1.first - p2.first;
    long long C = A * p1.first + B * p1.second;
    long long side1 = A * p3.first + B * p3.second - C;
    if (side1 == 0) {
        long long check1 = (p1.first - p3.first) * (p3.first - p2.first) >= 0;
        long long check2 = (p1.second - p3.second) * (p3.second - p2.second) >= 0;
        return check1 && check2;
    }
    return false;
}

int main(){
    ((void)0);
    ((void)0);
    long long k, n;
    cin >> k >> n;
    vector<Point> stones(k);
    for(auto& [x, y]: stones) cin >> x >> y;
    vector<Point> monsters(n);
    for(auto& [x, y]: monsters) cin >> x >> y;
    long long afraid = 0;
    for(const auto& m: monsters) {
        for(const auto& s1: stones) {
            bool hit = false;
            for(const auto& s2: stones) {
                if(s1 != s2 && canHit(s1, s2, m)) {
                    hit = true;
                    break;
                }
            }
            if(hit) {
                afraid++;
                break;
            }
        }
    }
    cout << afraid;
    return 0;
}