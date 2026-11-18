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
    ((void)0);
    ((void)0);
    int n;
    cin >> n;
    vector<string> nums(n);
    for(auto &x: nums) cin >> x;
    vector<vector<int>> cnt(10, vector<int>(10));
    for(const auto &x: nums){
        int len = x.size();
        for(int i=0; i<len; i++){
            cnt[len][x[i]-'0']++;
        }
    }
    vector<int> psum(100001, 0);
    for(int i=1; i<=100000; i++){
        psum[i] = (psum[i-1] + cnt[i].size()) % MOD;
    }
    ll ans = 0;
    for(int i=1; i<=100000; i++){
        for(int d=0; d<10; d++){
            if(cnt[i][d] == 0) continue;
            ll sum = 0;
            for(int j=i+1; j<=100000; j++){
                sum = (sum + 1LL * cnt[j][d] * psum[j-1]) % MOD;
                sum = (sum + 1LL * cnt[j][d] * (psum[100000] - psum[j]) * 2) % MOD;
            }
            ans = (ans + 1LL * sum * cnt[i][d] * d) % MOD;
            ans = (ans + 1LL * cnt[i][d] * cnt[i][d] * d * (psum[i-1] + (psum[100000] - psum[i]) * 2)) % MOD;
        }
    }
    cout << ans;
}