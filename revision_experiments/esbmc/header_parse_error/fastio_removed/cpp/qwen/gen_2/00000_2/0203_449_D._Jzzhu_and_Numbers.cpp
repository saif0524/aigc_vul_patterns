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

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;
const int MAX_MASK = (1 << 20) + 5;

int n;
int a[MAXN];
int dp[MAX_MASK];

int main(){
    ((void)0);
    ((void)0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    dp[0] = 1;
    for(int mask=1;mask<MAX_MASK;mask++){
        for(int i=0;i<n;i++){
            if((mask & a[i]) == 0){
                dp[mask] = (dp[mask] + dp[mask ^ a[i]]) % MOD;
            }
        }
    }
    long long ans = 0;
    for(int mask=1;mask<MAX_MASK;mask++){
        ans = (ans + dp[mask]) % MOD;
    }
    cout << ans << "\n";
    return 0;
}