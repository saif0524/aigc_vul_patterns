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
    int N, M;
    cin >> N >> M;
    vector<int> S(N), T(M);
    for(auto &x: S) { cin >> x; }
    for(auto &x: T) { cin >> x; }
    vector<vector<int>> dp(N+1, vector<int>(M+1, 0));
    dp[0][0] = 1;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=M;j++){
            if(i > 0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            if(j > 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
            if(i > 0 && j > 0 && S[i-1] == T[j-1]){
                dp[i][j] = (dp[i][j] - dp[i-1][j-1] + MOD) % MOD;
            }
            if(i > 0 && j > 0 && S[i-1] == T[j-1]){
                dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
            }
        }
    }
    cout << dp[N][M] << "\n";
}