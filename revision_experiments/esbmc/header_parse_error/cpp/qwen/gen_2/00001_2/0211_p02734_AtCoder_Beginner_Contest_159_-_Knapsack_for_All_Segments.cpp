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
    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    for(auto &a: A) cin >> a;

    vector<vector<int>> dp(N+1, vector<int>(S+1));
    dp[0][0] = 1;

    for(int i=1;i<=N;i++){
        for(int j=0;j<=S;j++){
            dp[i][j] = dp[i-1][j];
            if(j >= A[i-1]){
                dp[i][j] = (dp[i][j] + dp[i-1][j-A[i-1]]) % MOD;
            }
        }
    }

    long long result = 0;
    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j++){
            result = (result + dp[j][S] - dp[i-1][S] + MOD) % MOD;
        }
    }

    cout << result;
}