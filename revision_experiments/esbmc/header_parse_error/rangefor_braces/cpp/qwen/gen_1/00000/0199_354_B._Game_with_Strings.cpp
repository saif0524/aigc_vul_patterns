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
    int n;
    cin >> n;
    vector<string> T(n);
    for(auto &s : T) { cin >> s; }
    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][0] = (T[0][0] == 'a') - (T[0][0] == 'b');
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j){
            int val = (T[i][j] == 'a') - (T[i][j] == 'b');
            if(i) dp[i][j] = max(dp[i][j], dp[i-1][j] + val);
            if(j) dp[i][j] = max(dp[i][j], dp[i][j-1] + val);
        }
    if(dp[n-1][n-1] > 0) cout << "FIRST";
    else if(dp[n-1][n-1] < 0) cout << "SECOND";
    else cout << "DRAW";
}