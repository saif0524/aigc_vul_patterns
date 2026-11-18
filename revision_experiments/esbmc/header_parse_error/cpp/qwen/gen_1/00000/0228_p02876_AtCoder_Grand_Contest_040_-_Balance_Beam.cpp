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
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

struct Fraction {
    ll num, den;
    Fraction(ll n, ll d) {
        ll g = gcd(n, d);
        num = n / g;
        den = d / g;
    }
};

bool operator<(const Fraction &a, const Fraction &b) {
    return a.num * b.den < b.num * a.den;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<pair<ll, ll>> vs(N);
    for(auto &p : vs) cin >> p.first >> p.second;
    sort(begin(vs), end(vs), [&](const pair<ll, ll> &a, const pair<ll, ll> &b){
        return Fraction(a.second - a.first, a.second + a.first) < Fraction(b.second - b.first, b.second + b.first);
    });
    ll num = 0, den = 0;
    for(int i=0;i<N;i++){
        ll a = vs[i].first, b = vs[i].second;
        num += 2*a;
        den += a + b;
        if(num >= den){
            num -= den;
            den *= 2;
        }
    }
    Fraction ans(num, den);
    cout << ans.num << " " << ans.den;
}