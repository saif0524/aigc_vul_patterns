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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N, K;
    cin >> N >> K;
    vector<long long> a(N);
    for(long long &x: a) cin >> x;
    vector<long long> psum(N+1, 0);
    for(long long i=0; i<N; i++){
        psum[i+1] = psum[i] + a[i];
    }
    vector<long long> dp(N+1, 0);
    deque<long long> dq;
    for(long long i=1; i<=N; i++){
        while(!dq.empty() && dq.front() < i-K) dq.pop_front();
        long long best = dq.empty() ? 0 : dp[dq.front()];
        dp[i] = max(dp[i-1], best + psum[i] - psum[max(0LL, i-K)]);
        while(!dq.empty() && dp[i] >= dp[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }
    cout << max(0LL, dp[N]) << "\n";
}