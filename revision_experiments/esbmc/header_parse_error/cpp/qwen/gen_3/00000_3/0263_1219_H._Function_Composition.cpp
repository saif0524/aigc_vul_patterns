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

const int MAXN = 2e5 + 10;
const int MAXLOG = 64;

int n, q, A[MAXN];
int dp[MAXN][MAXLOG];

void precompute() {
    for(int i = 1; i <= n; i++) dp[i][0] = A[i];
    for(int j = 1; (1ll << j) <= MAXLOG; j++) {
        for(int i = 1; i <= n; i++) {
            if(dp[i][j - 1] == -1) dp[i][j] = -1;
            else dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }
}

int get(int x, long long m) {
    for(int j = MAXLOG - 1; j >= 0; j--) {
        if(m & (1ll << j)) {
            x = dp[x][j];
            if(x == -1) break;
        }
    }
    return x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> A[i];
    cin >> q;
    memset(dp, -1, sizeof(dp));
    precompute();
    while(q--){
        long long m;
        int y;
        cin >> m >> y;
        int result = 0;
        for(int i = 1; i <= n; i++) {
            if(get(i, m) == y) {
                result++;
            }
        }
        cout << result << "\n";
    }
}