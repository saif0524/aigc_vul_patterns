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

long long dp[101][4][2];

long long countNumbers(string &num, int pos, int nonZeroCount, int tight) {
    if (pos == num.size()) return nonZeroCount == 0;
    if (dp[pos][nonZeroCount][tight] != -1) return dp[pos][nonZeroCount][tight];
    long long limit = tight ? (num[pos] - '0') : 9;
    long long ans = 0;
    for (int it = 0; it <= limit; it++) {
        ans += countNumbers(num, pos + 1, nonZeroCount - (it > 0), tight && (it == limit));
    }
    return dp[pos][nonZeroCount][tight] = ans;
}

int main(){
    string N;
    int K;
    cin >> N >> K;
    memset(dp, -1, sizeof(dp));
    long long total = countNumbers(N, 0, K, 1);
    long long invalid = 0;
    for(int i = 1; i < K; ++i){
        memset(dp, -1, sizeof(dp));
        invalid += countNumbers(N, 0, i, 1);
    }
    cout << total - invalid;
}