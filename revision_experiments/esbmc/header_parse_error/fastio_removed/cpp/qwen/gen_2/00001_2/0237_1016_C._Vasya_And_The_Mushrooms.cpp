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
    vector<ll> a(n), b(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    vector<ll> sum_a(n+1, 0), sum_b(n+1, 0);
    for(int i=1;i<=n;i++){
        sum_a[i] = sum_a[i-1] + a[i-1];
        sum_b[i] = sum_b[i-1] + b[i-1];
    }
    ll max_sum = 0;
    for(int i=0;i<n;i++){
        ll cur_sum = sum_a[i+1] + sum_b[n] - sum_b[i] + (n-1-i)*b[i];
        max_sum = max(max_sum, cur_sum);
        cur_sum = sum_b[i+1] + sum_a[n] - sum_a[i] + (n-1-i)*a[i];
        max_sum = max(max_sum, cur_sum);
    }
    cout << max_sum;
}