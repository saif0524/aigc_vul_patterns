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
    int N, M;
    cin >> N >> M;
    vector<bool> broken(N+1, false);
    for(int i = 0; i < M; ++i){
        int a;
        cin >> a;
        broken[a] = true;
    }
    vector<long long> dp(N+1, 0);
    dp[0] = 1;
    if(!broken[1]) dp[1] = 1;
    for(int i = 2; i <= N; ++i){
        if(broken[i]) continue;
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }
    cout << dp[N];
}