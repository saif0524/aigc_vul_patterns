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
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<vector<long long>> dp(n+1, vector<long long>(k+1, 0));
    dp[0][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= k && j <= i - 1; j++){
            long long num = 0;
            for(int l = i; l >= 1 && i - l < 18; l--){
                num = (num * 10 + s[l-1] - '0') % MOD;
                if(s[l-1] != '0' || l == i){
                    dp[i][j] = (dp[i][j] + (j > 0 ? dp[l-1][j-1] : 0) * num) % MOD;
                }
            }
        }
    }

    cout << dp[n][k];
}