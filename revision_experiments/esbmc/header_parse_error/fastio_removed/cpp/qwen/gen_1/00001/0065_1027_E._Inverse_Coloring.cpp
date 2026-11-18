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

const int MOD = 998244353;
const int MAXN = 501;

int n, k;
int dp[MAXN][2];
bool valid[MAXN][MAXN];

int main(){
    ((void)0);
    ((void)0);
    cin >> n >> k;
    if(n == 1 && k == 1){
        cout << 0;
        return 0;
    }
    dp[1][0] = dp[1][1] = 2;
    for(int i = 2; i <= n; i++){
        dp[i][0] = (1LL * dp[i-1][0] * (dp[i-1][0] + dp[i-1][1])) % MOD;
        dp[i][1] = (1LL * dp[i-1][1] * (dp[i-1][0] + dp[i-1][1])) % MOD;
    }
    int ans = (dp[n][0] + dp[n][1]) % MOD;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= n - i + 1; j++){
            for(int l = 1; l <= n; l++){
                valid[j][l] = 1;
                valid[j+i-1][l] = 1;
            }
            for(int l = 2; l <= n - i + 1; l++){
                bool can = 1;
                for(int m = j; m <= j + i - 1; m++){
                    if(valid[m][l-1] || valid[m][l+i-1]){
                        can = 0;
                        break;
                    }
                }
                if(can){
                    int cnt = (dp[i][0] + dp[i][1]) % MOD;
                    for(int m = j; m <= j + i - 1; m++){
                        valid[m][l] = 1;
                        valid[m][l+i-1] = 1;
                    }
                    for(int m = j; m <= j + i - 1; m++){
                        for(int o = l; o <= l + i - 1; o++){
                            if(!valid[m][o]){
                                can = 0;
                                break;
                            }
                        }
                        if(!can) break;
                    }
                    if(can){
                        ans = (ans - (1LL * cnt * cnt) % MOD + MOD) % MOD;
                    }
                    for(int m = j; m <= j + i - 1; m++){
                        valid[m][l] = 0;
                        valid[m][l+i-1] = 0;
                    }
                }
            }
            for(int l = 1; l <= n; l++){
                valid[j][l] = 0;
                valid[j+i-1][l] = 0;
            }
        }
    }
    cout << ans;
}