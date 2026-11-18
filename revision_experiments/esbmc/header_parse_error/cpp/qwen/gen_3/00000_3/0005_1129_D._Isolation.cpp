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
const int MOD = 998244353;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    vector<int> dp(n+1, 0), freq(n+1, 0);
    dp[0] = 1;
    int unique = 0;
    for(int i=1; i<=n; i++){
        if(freq[a[i-1]] == 0) unique++;
        freq[a[i-1]]++;
        for(int j=i; j>=1; j--){
            if(unique <= k){
                dp[i] = (dp[i] + dp[j-1]) % MOD;
            }
            freq[a[j-1]]--;
            if(freq[a[j-1]] == 0) unique--;
            if(freq[a[j-1]] == 1) unique++;
            if(unique > k) break;
        }
    }
    cout << dp[n];
}