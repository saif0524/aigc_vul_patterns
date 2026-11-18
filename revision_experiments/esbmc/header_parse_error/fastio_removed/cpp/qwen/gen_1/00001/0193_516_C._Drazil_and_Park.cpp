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
    vector<ll> pre(n+1, 0);
    for(int i=0; i<n; ++i){
        pre[i+1] = pre[i] + d[i];
    }
    auto dist = [&](int a, int b){
        if(a > b) swap(a, b);
        return min(pre[b] - pre[a], pre[n] - (pre[b] - pre[a]));
    };
    while(m--){
        int a, b;
        cin >> a >> b;
        --a; --b;
        ll ans = 0;
        for(int c=0; c<n; ++c){
            if(c == a || c == b) continue;
            for(int d=c+1; d<n; ++d){
                if(d == a || d == b) continue;
                ll energy = 2*(h[c] + h[d]) + dist(c, d);
                ans = max(ans, energy);
            }
        }
        cout << ans << "\n";
    }
}