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

const int MOD = 1000000007;

int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    for(int i=0; i<n; i++) dp[i][i] = 1;
    for(int length=2; length<=n; length++){
        for(int i=0; i<=n-length; i++){
            int j = i + length - 1;
            if(s[i] == s[j]) dp[i][j] = (dp[i][j] + dp[i+1][j-1]) % MOD;
            dp[i][j] = (dp[i][j] + dp[i+1][j]) % MOD;
            dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
            dp[i][j] = (dp[i][j] - dp[i+1][j-1] + MOD) % MOD;
        }
    }
    cout << dp[0][n-1];
}