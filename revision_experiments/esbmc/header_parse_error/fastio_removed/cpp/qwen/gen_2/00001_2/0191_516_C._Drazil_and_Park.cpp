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
    int n, m;
    cin >> n >> m;
    vector<ll> d(n);
    for(auto &x: d) cin >> x;
    vector<ll> h(n);
    for(auto &x: h) cin >> x;
    vector<ll> pref(n+1, 0);
    for(int i=1;i<=n;i++) pref[i] = pref[i-1] + d[i-1];
    vector<ll> hmax(n), hmaxrev(n);
    hmax[0] = h[0];
    for(int i=1;i<n;i++) hmax[i] = max(hmax[i-1], h[i]);
    hmaxrev[n-1] = h[n-1];
    for(int i=n-2;i>=0;i--) hmaxrev[i] = max(hmaxrev[i+1], h[i]);
    while(m--){
        int a, b;
        cin >> a >> b;
        a--, b--;
        if(a > b) swap(a, b);
        ll d1 = pref[b+1] - pref[a];
        ll d2 = pref[n] - pref[b+1] + pref[a];
        ll dval = max(d1, d2);
        ll hval1 = a > 0 ? hmax[a-1] : 0;
        ll hval2 = hmaxrev[b+1];
        ll hval = max(hval1, hval2);
        cout << 2*hval + dval << "\n";
    }
}