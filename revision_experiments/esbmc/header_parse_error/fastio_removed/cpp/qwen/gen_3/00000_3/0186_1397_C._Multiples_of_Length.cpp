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

int main(){
    ((void)0);
    ((void)0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(auto &x: a) cin >> x;
    vector<ll> b(n, 0);
    int l = 1, r = n;
    if(a[0] != 0){
        b[0] = -a[0];
        cout << "1 1\n" << b[0] << "\n";
        a[0] = 0;
    }
    l = 1, r = n;
    while(a.back() != 0){
        b.back() = -a.back();
        a.back() = 0;
    }
    cout << n << " " << n << "\n" << b.back() << "\n";
    l = 1, r = n-1;
    while(l <= r){
        if(a[l-1] == 0){
            l++;
            continue;
        }
        if(a[r-1] == 0){
            r--;
            continue;
        }
        ll add = min(-a[l-1],-a[r-1]);
        b[l-1] += add;
        b[r-1] += add;
        a[l-1] += add;
        a[r-1] += add;
        l++, r--;
    }
    cout << "1 " << n-1 << "\n";
    for(int i=0;i<n-1;i++) cout << b[i] << " ";
    cout << "\n";
}