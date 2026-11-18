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
    vector<ll> c(n);
    for(auto &x: c) { cin >> x; }
    vector<ll> t(n);
    for(auto &x: t) { cin >> x; }
    if(c[0] != t[0] || c[n-1] != t[n-1]){
        cout << "No";
        return 0;
    }
    for(int i=1;i<n-1;i++){
        if(c[i] != t[i]){
            ll diff = t[i] - c[i];
            c[i-1] += diff;
            c[i+1] += diff;
            c[i] = t[i];
        }
    }
    for(int i=1;i<n-1;i++){
        if(c[i] != t[i]){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}