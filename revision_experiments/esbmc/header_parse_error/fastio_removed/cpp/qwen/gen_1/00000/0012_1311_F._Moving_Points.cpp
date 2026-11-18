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

int main(){
    ((void)0);
    ((void)0);
    int n;
    cin >> n;
    vector<long long> x(n), v(n);
    for(auto &xi : x) cin >> xi;
    for(auto &vi : v) cin >> vi;
    vector<pair<double, int>> slopes;
    for(int i = 0; i < n; i++){
        if(v[i] == 0) continue;
        double slope = -static_cast<double>(x[i]) / v[i];
        slopes.emplace_back(slope, i);
    }
    sort(slopes.begin(), slopes.end());
    long long ans = 0;
    for(int i = 0; i + 1 < n; i++){
        long long d = abs(x[i+1] - x[i]);
        if(v[i] == v[i+1]) ans += d;
        else ans += d * (v[i] < v[i+1]);
    }
    int last = 0;
    for(const auto &[slope, index] : slopes){
        ans += abs(x[last] + slope * v[last] - x[index]);
        last = index;
    }
    cout << ans;
}