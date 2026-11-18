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
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for(int &x : a) { cin >> x; }
    
    vector<int> dp(K + 1, 0);
    dp[0] = 1;
    
    for(int i = 0; i < N; ++i){
        vector<int> ndp(K + 1, 0);
        for(int j = 0; j <= K; ++j){
            for(int k = 0; k <= min(a[i], j); ++k){
                ndp[j] = (ndp[j] + dp[j - k]) % MOD;
            }
        }
        dp = move(ndp);
    }
    
    cout << dp[K] << "\n";
}