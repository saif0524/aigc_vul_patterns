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
long long freq[63];
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    long long a, MOD = 1000000007LL, tot = 0;
    for(int i = 0; i < n; ++i){
        cin >> a; for(long long j = 0; j < 63; ++j) if((a >> j) & 1) ++freq[j];
    }
    for(long long i = 0; i < 62; ++i) tot = (tot + (1LL << i) % MOD * freq[i] % MOD * (n - freq[i]) % MOD) % MOD;
    cout << tot << "\n";
}