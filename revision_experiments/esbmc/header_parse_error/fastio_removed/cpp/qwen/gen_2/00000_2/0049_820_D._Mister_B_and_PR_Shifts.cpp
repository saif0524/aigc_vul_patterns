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
    vector<int> p(n);
    for(int &x : p) cin >> x;
    vector<ll> pref(n+1, 0);
    for(int i=0;i<n;i++){
        pref[i+1] = pref[i] + abs(p[i] - (i+1));
    }
    ll total = pref[n];
    ll ans = total;
    int id = 0;
    for(int k=1;k<n;k++){
        ll dev = total - (pref[n] - pref[k]) + (pref[k] - pref[0] - (n-k));
        if(dev < ans){
            ans = dev;
            id = k;
        }
    }
    cout << ans << " " << id << "\n";
}