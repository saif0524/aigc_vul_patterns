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
    long long I;
    cin >> n >> I;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    I *= 8;
    int ans = n;
    for(int i=0; i<n; ++i){
        int l = a[i];
        auto it = upper_bound(a.begin(), a.end(), l);
        int cur = i;
        for(int j=i; j<n; ++j){
            it = upper_bound(it, a.end(), a[j]);
            int r = a[j];
            int k = 1;
            if(it != a.end()) k = 32 - __builtin_clz(it - a.begin() - (j - i) + cur);
            if(1LL * k * (n - cur) <= I){
                ans = min(ans, cur + (n - (it - a.begin())));
            }
            cur = it - a.begin();
        }
        break;
    }
    cout << ans;
}