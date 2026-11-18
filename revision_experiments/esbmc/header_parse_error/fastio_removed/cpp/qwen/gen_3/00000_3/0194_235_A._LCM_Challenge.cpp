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

ll lcm(ll a, ll b) {
    return (a / __gcd(a, b)) * b;
}

ll maxLCM(ll n) {
    ll maxlcm = 1;
    for (ll i = n; i >= max(1LL, n - 2); --i) {
        for (ll j = n; j >= max(1LL, n - 2); --j) {
            for (ll k = n; k >= max(1LL, n - 2); --k) {
                maxlcm = max(maxlcm, lcm(lcm(i, j), k));
            }
        }
    }
    return maxlcm;
}

int main(){
    ((void)0);
    ((void)0);
    ll n;
    cin >> n;
    cout << maxLCM(n) << "\n";
    return 0;
}