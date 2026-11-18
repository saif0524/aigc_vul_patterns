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

typedef long long ll;
const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> S(N), T(M);
    for(auto& x : S) cin >> x;
    for(auto& x : T) cin >> x;

    unordered_map<int, vector<int>> idxS, idxT;
    for(int i = 0; i < N; i++) idxS[S[i]].push_back(i);
    for(int i = 0; i < M; i++) idxT[T[i]].push_back(i);

    vector<vector<ll>> dp(N + 1, vector<ll>(M + 1, 0));
    dp[0][0] = 1;

    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= M; j++){
            if(i < N) dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
            if(j < M) dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
            if(i < N && j < M && S[i] == T[j]){
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
            }
        }
    }

    ll ans = 0;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= M; j++){
            ans = (ans + dp[i][j]) % MOD;
        }
    }

    cout << ans << "\n";
    return 0;
}