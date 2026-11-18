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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> dp(n, 1);
    for(int i = 1; i < n; ++i){
        if(s[i] == s[i-1]){
            dp[i] = (dp[i] + dp[i-1]) % MOD;
        }
        for(int j = i-2; j >= 0; --j){
            if(s[j] == s[i]){
                dp[i] = (dp[i] + dp[j]) % MOD;
                break;
            }
        }
    }
    long long ans = 0;
    for(int i = 0; i < n; ++i){
        ans = (ans + dp[i]) % MOD;
    }
    cout << ans;
}