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
const int MAXN = 705;

int dp[MAXN][2][2];

int main(){
    string s;
    cin >> s;
    int n = s.size();
    stack<int> st;
    for(int i=0; i<n; i++){
        if(s[i] == '(') st.push(i);
    }
    vector<int> match(n);
    for(int i=n-1; i>=0; i--){
        if(s[i] == ')'){
            match[i] = st.top(); st.pop();
            match[match[i]] = i;
        }
    }
    dp[0][1][0] = 2;
    dp[0][0][1] = 2;
    for(int i=1; i<n; i++){
        if(s[i] == '('){
            dp[i][1][0] = (dp[i][1][0] + dp[i-1][1][0]) % MOD;
            dp[i][1][0] = (dp[i][1][0] + dp[i-1][0][1]) % MOD;
            dp[i][0][1] = (dp[i][0][1] + dp[i-1][1][0]) % MOD;
            dp[i][0][1] = (dp[i][0][1] + dp[i-1][0][1]) % MOD;
        }
        else{
            int m = match[i];
            dp[i][1][0] = (dp[i][1][0] + dp[m-1][0][1]) % MOD;
            dp[i][0][1] = (dp[i][0][1] + dp[m-1][1][0]) % MOD;
            if(m > 1){
                dp[i][1][0] = (dp[i][1][0] + dp[m-2][1][0]) % MOD;
                dp[i][0][1] = (dp[i][0][1] + dp[m-2][0][1]) % MOD;
            }
        }
    }
    int ans = 0;
    ans = (ans + dp[n-1][1][0]) % MOD;
    ans = (ans + dp[n-1][0][1]) % MOD;
    cout << ans;
}