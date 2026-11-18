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

const int MOD = 1e9 + 7;

long long addMod(long long a, long long b) {
    return (a % MOD + b % MOD) % MOD;
}

long long multMod(long long a, long long b) {
    return (a % MOD * b % MOD) % MOD;
}

int main(){
    ((void)0);
    ((void)0);
    int t;
    cin >> t;
    while(t--){
        long long n, m;
        cin >> n >> m;
        long long length = 0;
        while(n > 0){
            int digit = n % 10;
            length = addMod(length, multMod(multMod(m + 1, digit), 1LL));
            n /= 10;
        }
        cout << length << "\n";
    }
}