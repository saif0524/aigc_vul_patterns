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
    int n, t;
    ll k;
    cin >> n >> t >> k;
    vector<ll> a(n), b(n), c(n);
    for(int i=0; i<n; i++) cin >> a[i] >> b[i] >> c[i];
    
    int lo = 0, hi = t * n, ans = t * n;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        vector<ll> p = a;
        vector<ll> used(t, 0);
        bool ok = true;
        for(int h=0; h<t && ok; h++){
            ll capacity = (ll)mid * k;
            for(int i=0; i<n && ok; i++){
                if(p[i] > c[i]){
                    ok = false;
                    break;
                }
                if(p[i] > 0){
                    ll take = min(p[i], capacity);
                    p[i] -= take;
                    capacity -= take;
                }
            }
            if(!ok) break;
            for(int i=0; i<n; i++){
                p[i] += b[i];
            }
            if(capacity > 0){
                used[h] = min(mid, (int)(capacity/k));
                mid -= used[h];
            }
        }
        if(ok){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    cout << ans;
}