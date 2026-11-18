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
    ((void)0);
    ((void)0);
    int n, k;
    cin >> n >> k;
    vector<array<int, 4>> books(n);
    for(int i=0;i<n;i++){
        cin >> books[i][0] >> books[i][1] >> books[i][2];
        books[i][3] = i;
    }
    vector<vector<int>> dp(k+1, vector<int>(k+1, 1e9));
    dp[0][0] = 0;
    for(auto &book : books){
        for(int i=k;i>=0;i--){
            for(int j=k;j>=0;j--){
                if(i-book[1]>=0){
                    dp[i][j] = min(dp[i][j], dp[i-book[1]][j] + book[0]);
                }
                if(j-book[2]>=0){
                    dp[i][j] = min(dp[i][j], dp[i][j-book[2]] + book[0]);
                }
                if(i-book[1]>=0 && j-book[2]>=0){
                    dp[i][j] = min(dp[i][j], dp[i-book[1]][j-book[2]] + book[0]);
                }
            }
        }
    }
    int ans = 1e9;
    for(int i=k;i<=k;i++){
        for(int j=k;j<=k;j++){
            ans = min(ans, dp[i][j]);
        }
    }
    if(ans == 1e9){
        cout << -1;
    } else {
        cout << ans;
    }
}