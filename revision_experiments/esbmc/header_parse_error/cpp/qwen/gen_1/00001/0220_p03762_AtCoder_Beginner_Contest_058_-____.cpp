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

const int MOD = 1000000007;

int main(){
    int n, m;
    cin >> n >> m;
    vector<long long> x(n), y(m);
    for(auto &i: x) cin >> i;
    for(auto &i: y) cin >> i;
    
    long long sumX = 0, sumY = 0;
    for(int i=1; i<n; ++i){
        sumX += (x[i] - x[i-1]) * 1LL * (n-i);
        sumX %= MOD;
    }
    for(int i=1; i<m; ++i){
        sumY += (y[i] - y[i-1]) * 1LL * (m-i);
        sumY %= MOD;
    }
    
    long long result = (sumX * sumY) % MOD;
    cout << result;
}