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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(auto &x: a) cin >> x;
    vector<ll> b(n, 0);
    if(n >= 1){
        ll x = a[0];
        b[0] = -x;
        cout << "1 1\n" << b[0] << "\n";
        a[0] += b[0];
    }
    if(n >= 2){
        ll x = a[1];
        b[1] = -x;
        cout << "2 2\n" << b[1] << "\n";
        a[1] += b[1];
    }
    if(n >= 3){
        ll x = a[2];
        b[2] = -x;
        cout << "3 3\n" << b[2] << "\n";
        a[2] += b[2];
    }
    if(n >= 4){
        for(int i=3;i<n;i++){
            b[i] = -a[i];
            a[i] += b[i];
        }
        cout << "4 " << n << "\n";
        for(int i=3;i<n;i++) cout << b[i] << " ";
        cout << "\n";
    }
}