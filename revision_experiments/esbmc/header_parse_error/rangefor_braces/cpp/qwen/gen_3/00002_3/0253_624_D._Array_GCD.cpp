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
    long long n, a, b;
    cin >> n >> a >> b;
    vector<long long> arr(n);
    for(auto &x: arr) { cin >> x; }
    
    auto g = [&](long long x, long long y){
        while(y){
            long long t = y;
            y = x % y;
            x = t;
        }
        return x;
    };
    
    long long ans = LLONG_MAX;
    
    // Case: Removing a subsegment
    vector<long long> pref(n+1);
    for(long long i=1; i<=n; i++) pref[i] = g(pref[i-1], arr[i-1]);
    
    for(long long i=1; i<n; i++){
        long long current = a * i;
        long long suf = arr[i];
        for(long long j=i+1; j<n; j++) suf = g(suf, arr[j]);
        if(pref[i] > 1 || suf > 1) ans = min(ans, current);
    }
    
    // Case: Changing elements
    for(long long x=2; x<=1000; x++){
        long long current = 0;
        for(auto &y: arr){
            if(y % x != 0) current += b * min(y % x, x - y % x);
        }
        if(current < ans) ans = current;
    }
    
    cout << ans;
}