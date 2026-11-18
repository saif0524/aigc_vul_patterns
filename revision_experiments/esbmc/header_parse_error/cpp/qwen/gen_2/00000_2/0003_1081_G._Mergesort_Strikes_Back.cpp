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

ll modpow(ll base, ll exp, ll mod) {
    ll result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> inversions(n+1, 0);
    inversions[0] = 1;
    for(int i = 1; i <= n; i++){
        inversions[i] = inversions[i-1] * (2 * i - 1) % q;
        inversions[i] = inversions[i] * modpow(i + 1, q-2, q) % q;
    }
    ll expected_inversions = 0;
    for(int i = 1; i < (1<<min(k, (int)log2(n)+1)); i++){
        int cnt = __builtin_popcount(i);
        ll mult = inversions[cnt];
        if(cnt % 2 == 1) mult = q - mult;
        if(i == (1<<min(k, (int)log2(n)+1))-1 && cnt == k+1) mult = q - mult;
        expected_inversions = (expected_inversions + mult) % q;
    }
    expected_inversions = expected_inversions * modpow((1<<min(k, (int)log2(n)+1))-1, q-2, q) % q;
    ll total_permutations = modpow(2, n*(n-1)/2, q);
    ll ans = expected_inversions * modpow(total_permutations, q-2, q) % q;
    cout << ans;
}