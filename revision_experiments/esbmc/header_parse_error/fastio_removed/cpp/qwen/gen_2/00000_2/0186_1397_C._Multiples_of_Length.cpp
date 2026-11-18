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
    if(n == 1){
        cout << "1 1\n" << -a[0] << "\n1 1\n0\n1 1\n0\n";
        return 0;
    }
    
    // Operation 1
    ll sum1 = 0;
    for(int i=0;i<n-1;i++){
        b[i] = -a[i];
        sum1 += b[i];
    }
    b[n-1] = -sum1 - a[n-1];
    cout << "1 " << n << "\n";
    for(int i=0;i<n;i++) cout << b[i] << " \n"[i==n-1];
    
    // Reset b
    fill(b.begin(), b.end(), 0);
    ll sum2 = 0;
    for(int i=1;i<n;i++){
        b[i] = -a[i];
        sum2 += b[i];
    }
    b[0] = -sum2 - a[0];
    cout << "1 " << n << "\n";
    for(int i=0;i<n;i++) cout << b[i] << " \n"[i==n-1];
    
    // Reset b
    fill(b.begin(), b.end(), 0);
    if(n >= 3){
        b[n-1] = sum1 + sum2 + 2*a[n-1];
        cout << n << " " << n << "\n";
        cout << b[n-1] << "\n";
    } else {
        cout << "1 1\n";
        cout << "0\n";
    }
}