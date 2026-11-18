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
    for(auto &x: a) { cin >> x; }
    if(n==1){
        cout << "1 1\n" << -a[0] << "\n";
        cout << "1 1\n0\n";
        cout << "1 1\n0\n";
        return 0;
    }
    cout << "1 1\n" << -a[0] << "\n";
    cout << n-1 << n << "\n";
    ll val = a[n-2]+a[n-1];
    cout << val << " " << -val << "\n";
    cout << "2 " << n << "\n";
    for(int i=1;i<n;i++) cout << -a[i]-(i==n-1?val:0) << (i==n-1?"\n":" ");
}