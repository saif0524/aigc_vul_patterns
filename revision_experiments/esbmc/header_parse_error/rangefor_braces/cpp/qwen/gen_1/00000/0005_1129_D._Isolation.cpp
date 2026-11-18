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

const int MOD = 998244353;

int main(){
    ((void)0);
    ((void)0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x : a) { cin >> x; }
    vector<int> freq(n + 1, 0);
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    int distinct_once = 0;
    for(int i = 1; i <= n; ++i){
        if(++freq[a[i-1]] == 1) distinct_once++;
        if(freq[a[i-1]] == 2) distinct_once--;
        if(distinct_once <= k) dp[i] = dp[i-1];
        dp[i] = (dp[i] + dp[i-1]) % MOD;
        if(i > k){
            if(--freq[a[i-k-1]] == 1) distinct_once++;
            if(freq[a[i-k-1]] == 0) distinct_once--;
        }
    }
    cout << dp[n] << "\n";
}