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

typedef long double ld;

const int N = 10010;
int n, w, v, u;
ld x[N], y[N];

bool check(ld t) {
    for (int i = 0; i < n; ++i) {
        ld nx = x[i] - v * t;
        ld ny = y[i];
        ld nx1 = x[(i + 1) % n] - v * t;
        ld ny1 = y[(i + 1) % n];
        if (nx * ny1 - nx1 * ny < 0) {
            swap(nx, nx1);
            swap(ny, ny1);
        }
        if (nx <= 0 && nx1 >= 0 && ny >= 0 && ny1 <= w && nx * (w - ny) + (ny1 - ny) * (-nx1) + nx1 * (w - ny1) >= 0 && nx * (-ny) + (ny1 - ny) * (nx1) + nx1 * (-ny1) <= 0) {
            return false;
        }
    }
    return true;
}

int main(){
    ((void)0);
    ((void)0);
    cin >> n >> w >> v >> u;
    for(int i=0;i<n;i++) cin >> x[i] >> y[i];
    ld l = 0, r = 1e18;
    for(int it=0;it<50;++it){
        ld m = (l+r)/2;
        if(check(m)) r=m;
        else l=m;
    }
    cout << fixed << setprecision(10) << max(l, ld(w)/u);
}