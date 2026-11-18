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

const int MOD = 1009;
const int MAXN = 200005;
const int MAXM = 1000;

int n, m, k;
int cnt[MAXM + 1];
int dp[MAXN][MAXM + 1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        cnt[c]++;
    }
    dp[0][0] = 1;
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = dp[i][j-1];
            for(int x = 1; x <= cnt[j] && x <= i; x++){
                dp[i][j] = (dp[i][j] + dp[i-x][j-1]) % MOD;
            }
        }
    }
    cout << dp[k][m] << "\n";
}