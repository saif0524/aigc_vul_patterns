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
const int MAXN = 3000 + 5;
const int MAXS = 3000 + 5;

int dp[MAXN][MAXS];
int prefix_dp[MAXN][MAXS];
int main(){
    ((void)0);
    ((void)0);
    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    for(int &x : A) { cin >> x; }
    for(int i=0;i<N;i++){
        dp[i][0] = 1;
        prefix_dp[i][0] = 1;
    }
    for(int i=0;i<N;i++){
        for(int j=1;j<=S;j++){
            dp[i][j] = 0;
            if(i > 0){
                dp[i][j] = (dp[i][j] + prefix_dp[i-1][j]) % MOD;
            }
            if(j >= A[i] && i > 0){
                dp[i][j] = (dp[i][j] - prefix_dp[i-1][j - A[i]] + MOD) % MOD;
                dp[i][j] = (dp[i][j] + dp[i-1][j - A[i]]) % MOD;
            }
            else if(j >= A[i]){
                dp[i][j] = 1;
            }
            prefix_dp[i][j] = (prefix_dp[i][j-1] + dp[i][j]) % MOD;
        }
    }
    int ans = 0;
    for(int i=0;i<N;i++){
        ans = (ans + prefix_dp[i][S]) % MOD;
    }
    cout << ans;
}