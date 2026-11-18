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

const int MOD = 1009;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> cnt(m + 1, 0);
    for(int i = 0; i < n; ++i){
        int c;
        cin >> c;
        cnt[c]++;
    }
    vector<vector<int>> dp(k + 1, vector<int>(m + 1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= k; ++i){
        for(int c = 0; c <= m; ++c){
            dp[i][c] = dp[i-1][c];
            if(c > 0){
                for(int j = 1; j <= cnt[c] && j <= i; ++j){
                    dp[i][c] = (dp[i][c] + dp[i-j][c-1]) % MOD;
                }
            }
        }
    }
    int result = 0;
    for(int c = 1; c <= m; ++c){
        result = (result + dp[k][c]) % MOD;
    }
    cout << result;
}