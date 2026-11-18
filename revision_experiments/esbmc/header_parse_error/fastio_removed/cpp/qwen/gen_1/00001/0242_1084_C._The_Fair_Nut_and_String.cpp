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

int main(){
    ((void)0);
    ((void)0);
    string s;
    cin >> s;
    int n = s.size();
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    long long cnt_b = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] == 'b'){
            cnt_b = (cnt_b + dp[i]) % MOD;
        } else if(s[i] == 'a'){
            dp[i + 1] = (dp[i] + cnt_b) % MOD;
        }
    }
    long long ans = 0;
    for(int i = 0; i <= n; ++i){
        if(s[i - 1] == 'a'){
            ans = (ans + dp[i]) % MOD;
        }
    }
    cout << ans;
}