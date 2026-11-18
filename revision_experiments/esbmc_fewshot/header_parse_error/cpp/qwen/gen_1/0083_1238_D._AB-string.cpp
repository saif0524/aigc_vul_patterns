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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<long long> dp(n+1, 0);
    long long ans = 0;
    for(int i=0;i<n;i++){
        dp[i+1] = dp[i];
        if(i-1>=0&& s[i]==s[i-1]){
            dp[i+1] = max(dp[i+1], (long long)i-1+1);
        }
        if(i-2>=0&& s[i]==s[i-2]){
            dp[i+1] = max(dp[i+1], (long long)i-2+1);
        }
    }
    for(int i=n-1;i>=0;i--){
        if(i+1<n && s[i]==s[i+1]){
            dp[i] = max(dp[i], dp[i+2]+2);
        }
        if(i+2<n && s[i]==s[i+2]){
            dp[i] = max(dp[i], dp[i+3]+3);
        }
        ans += dp[i];
    }
    cout << ans;
}