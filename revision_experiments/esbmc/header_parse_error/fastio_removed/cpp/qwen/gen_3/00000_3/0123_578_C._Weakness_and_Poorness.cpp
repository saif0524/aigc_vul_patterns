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
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    
    long long sum = 0;
    for(auto x: a) sum += x;
    
    vector<long long> pref_min(n+1, 0), pref_max(n+1, 0);
    for(int i=0; i<n; ++i){
        pref_min[i+1] = min(pref_min[i], 1LL*a[i]);
        pref_max[i+1] = max(pref_max[i], 1LL*a[i]);
    }
    
    double ans = 1e18;
    for(int i=0; i<=n; ++i){
        long long mx = max(pref_max[i] - pref_min[n] + pref_min[i], pref_max[n] - pref_max[i] + pref_min[n] - pref_min[i]);
        ans = min(ans, (double)(sum - mx) / 2.0);
    }
    
    cout << fixed << setprecision(15) << ans;
    return 0;
}