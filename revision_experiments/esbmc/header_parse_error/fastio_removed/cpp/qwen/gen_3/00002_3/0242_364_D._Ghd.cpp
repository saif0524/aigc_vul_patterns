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

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

int main(){
    ((void)0);
    ((void)0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(auto &x : a) cin >> x;
    map<ll, int> factors;
    for(const auto &x : a){
        for(ll i = 2; i * i <= x; i++){
            while(x % i == 0){
                factors[i]++;
                x /= i;
            }
        }
        if(x > 1) factors[x]++;
    }
    int half = (n + 1) / 2;
    ll result = 1;
    for(const auto &[p, cnt] : factors){
        if(cnt >= half){
            int k = cnt / half;
            result *= pow(p, k);
        }
    }
    cout << result;
}