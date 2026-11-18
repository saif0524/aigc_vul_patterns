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
    vector<string> grid(n);
    for(auto &row: grid) { cin >> row; }
    
    // dp[r][c][0]: max a's for path ending at (r,c)
    // dp[r][c][1]: max b's for path ending at (r,c)
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(2, 0)));
    dp[1][1][grid[0][0] == 'a'] = 1;

    for(int r = 1; r <= n; ++r){
        for(int c = 1; c <= n; ++c){
            int a_val = grid[r-1][c-1] == 'a';
            int b_val = grid[r-1][c-1] == 'b';
            
            dp[r][c][0] = max(dp[r-1][c][0] + a_val, dp[r][c-1][0] + a_val);
            dp[r][c][1] = max(dp[r-1][c][1] + b_val, dp[r][c-1][1] + b_val);
        }
    }

    int a_count = dp[n][n][0];
    int b_count = dp[n][n][1];
    
    if(a_count > b_count) cout << "FIRST";
    else if(b_count > a_count) cout << "SECOND";
    else cout << "DRAW";
}