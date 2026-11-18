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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> a(n), b(m);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    long long l = lcm(n, m);
    long long d = 0;
    for(long long i = 0; i < l; ++i){
        if(a[i % n] != b[i % m]) ++d;
    }
    long long cycles = (k + d - 1) / d;
    long long rem = k - (cycles - 1) * d;
    long long i = 0;
    while(rem > 0){
        if(a[i % n] != b[i % m]) --rem;
        ++i;
    }
    cout << (cycles - 1) * l + i;
}