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
    int k;
    cin >> k;
    vector<int> c(k);
    int total = 0;
    for(int &x : c){
        cin >> x;
        total += x;
    }
    vector<vector<long long>> dp(total + 1, vector<long long>(k + 1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= total; ++i){
        for(int j = 1; j <= k; ++j){
            if(c[j-1] > 0){
                for(int l = 0; l < j; ++l){
                    dp[i][j] = (dp[i][j] + dp[i-1][l]) % MOD;
                }
            }
        }
    }
    long long result = 0;
    for(int j = 1; j <= k; ++j){
        result = (result + dp[total][j]) % MOD;
    }
    cout << result;
}