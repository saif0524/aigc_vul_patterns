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

const db PI = acos(-1.0);

db area_polygon(const vector<pair<db, db>> &points) {
    int n = points.size();
    db area = 0.0;
    for(int i=0; i<n; i++) {
        int j = (i + 1) % n;
        area += points[i].first * points[j].second;
        area -= points[j].first * points[i].second;
    }
    return fabs(area) / 2.0;
}

int main(){
    ((void)0);
    ((void)0);
    int n;
    db px, py;
    cin >> n >> px >> py;
    vector<pair<db, db>> points(n);
    for(int i=0;i<n;i++){
        cin >> points[i].first >> points[i].second;
        points[i].first -= px;
        points[i].second -= py;
    }
    db area = area_polygon(points);
    cout << fixed << setprecision(15) << 2*PI*area << endl;
}