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
    string s;
    cin >> s;
    int n = s.size();
    vector<long long> dp(n+1, 0), dp2(n+1, 0), f(n+1, 0), f2(n+1, 0);
    dp[0] = f[0] = 1;
    for(int i = 1; i <= n; ++i){
        if(s[i-1] == '('){
            dp[i] = (dp[i-1] + f[i-1]) % MOD;
            f[i] = (f[i-1] * 2) % MOD;
        }
        else if(s[i-1] == ')'){
            dp[i] = f2[i-1];
            f[i] = 0;
        }
        else{
            dp[i] = (dp[i-1] + f[i-1] + f2[i-1]) % MOD;
            f[i] = (f[i-1] * 2 + f2[i-1]) % MOD;
        }
        if(s[i-1] == ')'){
            dp2[i] = (dp2[i-1] + dp[i-1]) % MOD;
            f2[i] = (f2[i-1] * 2 + f[i-1]) % MOD;
        }
        else if(s[i-1] == '('){
            dp2[i] = f[i-1];
            f2[i] = (f[i-1] * 2) % MOD;
        }
        else{
            dp2[i] = (dp2[i-1] + dp[i-1] + f[i-1]) % MOD;
            f2[i] = (f2[i-1] * 2 + f[i-1] * 2) % MOD;
        }
    }
    cout << (dp[n] + dp2[n]) % MOD;
    return 0;
}