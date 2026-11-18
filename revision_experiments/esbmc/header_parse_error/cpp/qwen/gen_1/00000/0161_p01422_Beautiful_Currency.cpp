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

const int MAXN = 25;
const double EPS = 1e-9;

int a[MAXN];

double check(double max_ratio) {
    vector<double> b;
    for (int i = 0; i < N; i++) {
        double lo = a[i] * (1 - max_ratio);
        double hi = a[i] * (1 + max_ratio);
        if (b.empty()) {
            b.push_back(lo);
        } else {
            if (b.back() + EPS > hi) return 1e9;
            lo = max(lo, b.back() + EPS);
            b.push_back(lo);
        }
    }
    for (int i = 1; i < N; i++) {
        if (fabs(fmod(b[i], b[i-1])) > EPS) return 1e9;
    }
    return b[N-1];
}

int main(){
    int N;
    cin >> N;
    for(int i = 0 ; i < N ; i++) cin >> a[i];
    double lo = 0, hi = 1.0;
    while(hi - lo > EPS){
        double mid = (lo+hi)/2.0;
        double mx = check(mid);
        if(mx < 1e9) hi=mid;
        else lo=mid;
    }
    printf("%.10f\n",lo);
}