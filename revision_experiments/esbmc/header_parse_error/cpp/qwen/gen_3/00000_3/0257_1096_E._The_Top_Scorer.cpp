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
const int MAX = 5005;

long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

long long inv(long long x) {
    return modPow(x, MOD - 2, MOD);
}

int main(){
    int p, s, r;
    cin >> p >> s >> r;
    vector<long long> dp(s+1,0);
    dp[0] = 1;
    for(int i=1; i<p; i++){
        vector<long long> new_dp(s+1,0);
        long long sum = 0;
        for(int j=0; j<=s; j++){
            sum += dp[j];
            sum %= MOD;
            if(j <= s - i)
                new_dp[j+i] = sum;
        }
        dp.swap(new_dp);
    }
    long long total = 0;
    for(int i=0; i<=s-r; i++){
        total = (total + dp[i]) % MOD;
    }
    long long wins = 0;
    for(int i=r+1; i<=s; i++){
        wins = (wins + dp[s-i]) % MOD;
    }
    long long ties = dp[s-r];
    if(ties > 0){
        wins = (wins + ties * modPow(2, MOD - 2, MOD)) % MOD;
    }
    if(total == 0){
        cout << 0 << endl;
        return 0;
    }
    cout << (wins * inv(total)) % MOD << endl;
}