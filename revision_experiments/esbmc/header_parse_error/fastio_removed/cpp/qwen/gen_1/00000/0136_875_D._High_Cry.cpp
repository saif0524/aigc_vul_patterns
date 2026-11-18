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
    int max_bit = 0;
    for(int i=0; i<n; ++i){
        max_bit = max(max_bit, 31 - __builtin_clz(a[i]|1));
    }
    vector<int> count(1 << (max_bit+1), 0);
    for(int i=0; i<n; ++i){
        count[a[i]]++;
    }
    for(int i=1; i<(1 << (max_bit+1)); ++i){
        count[i] += count[i-1];
    }
    long long ans = 0;
    for(int i=0; i<n; ++i){
        int c = count[a[i]-1];
        int mask = 0;
        for(int j=0; j<=max_bit; ++j){
            if(((a[i] >> j) & 1) == 0){
                mask |= (1 << j);
                c -= count[mask];
            }
        }
        ans += i - c;
    }
    cout << ans;
}