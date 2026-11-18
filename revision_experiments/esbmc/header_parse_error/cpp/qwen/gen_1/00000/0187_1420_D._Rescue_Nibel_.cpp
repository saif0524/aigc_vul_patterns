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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> intervals(n);
    for(auto &p : intervals) cin >> p.first >> p.second;
    sort(intervals.begin(), intervals.end(), [](const pair<int, int> &a, const pair<int, int> &b){
        if(a.second == b.second) return a.first > b.first;
        return a.second < b.second;
    });
    vector<int> dp(k+1, 0);
    dp[0] = 1;
    long long sum = 0;
    int last_end = -1;
    for(int i = 0; i < n; ++i){
        int start = intervals[i].first;
        int end = intervals[i].second;
        if(start > last_end){
            for(int j = k; j > 0; --j) dp[j] = (sum + (j < k ? dp[j] : 0)) % MOD;
            sum = (sum * 2) % MOD;
            sum = (sum + dp[0]) % MOD;
            last_end = end;
        }
        sum = (sum - dp[k] + MOD) % MOD;
        dp[k] = (dp[k] + dp[k-1]) % MOD;
        for(int j = k-1; j > 0; --j) dp[j] = (dp[j] + dp[j-1]) % MOD;
        dp[0] = (dp[0] + 1) % MOD;
    }
    cout << dp[k];
}