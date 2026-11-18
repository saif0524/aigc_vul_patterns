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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    ll min_moves = LLONG_MAX;
    vector<ll> suffix_sum(n+1, 0);
    for(int i=n-1; i>=0; --i) suffix_sum[i] = suffix_sum[i+1] + a[i];
    for(int i=0; i+k-1<n; ++i){
        int target = a[i+k-1];
        ll left_moves = 1LL * target * i - (suffix_sum[0] - suffix_sum[i]);
        ll right_moves = (suffix_sum[i+k] - suffix_sum[i+k-1]) - 1LL * target * (n-i-k);
        min_moves = min(min_moves, left_moves + right_moves);
    }
    cout << min_moves;
}