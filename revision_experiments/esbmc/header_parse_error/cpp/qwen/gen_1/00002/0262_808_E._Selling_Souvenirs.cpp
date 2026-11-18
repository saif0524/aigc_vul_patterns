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
    long long n, m;
    cin >> n >> m;
    vector<vector<long long>> dp(4, vector<long long>(m+1, 0));
    for(long long i = 0; i < n; ++i){
        long long w, c;
        cin >> w >> c;
        for(long long j = m; j >= w; --j){
            dp[w][j] = max(dp[w][j], dp[w-w][j-w] + c);
        }
    }
    long long max_cost = 0;
    for(long long i = 0; i <= m; ++i){
        for(long long j = 0; j < 4; ++j){
            max_cost = max(max_cost, dp[j][i]);
        }
    }
    cout << max_cost;
}