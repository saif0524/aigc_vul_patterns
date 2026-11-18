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

const int64_t MOD = 1e9+7;

void add(int64_t& a, int64_t b){
    a = (a+b)%MOD;
}
int nth_bit(int64_t num , int n) {
    return (num >> n) & 1;
}

int main() {
    int64_t N;
    cin >> N;

    int64_t dp[61][3] = {0};
    dp[60][0] = 1;

    for(int d = 59; d >= 0; d--) {
        for(int s = 0; s <= 2; s++) {
            for (int k = 0; k <= 2; k++) {
                int s2 = min(2, 2*s+nth_bit(N, d) - k);
                if (s2 >= 0) add(dp[d][s2], dp[d+1][s]);
            }

        }
    }


    int64_t ans = (dp[0][0] + dp[0][1] + dp[0][2]) % MOD;
    cout << ans << endl;
    return 0;
}