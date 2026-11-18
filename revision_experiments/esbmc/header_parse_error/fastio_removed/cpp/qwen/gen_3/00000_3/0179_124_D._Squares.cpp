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
    ll a, b, x1, y1, x2, y2;
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;
    auto is_bad = [&](ll x, ll y){
        return (abs(x + y) % (1LL << a) == 0) || (abs(x - y) % (1LL << b) == 0);
    };
    ll ans = LLONG_MAX;
    for(ll dx = -1; dx <= 1; dx++){
        for(ll dy = -1; dy <= 1; dy++){
            if(abs(dx) + abs(dy) > 1) continue;
            ll cx = x1 + dx, cy = y1 + dy;
            if(is_bad(cx, cy)){
                ll steps = abs(cx - x2) + abs(cy - y2);
                ans = min(ans, steps + 1);
            }
        }
    }
    if(ans == LLONG_MAX) ans = 0;
    cout << ans;
}