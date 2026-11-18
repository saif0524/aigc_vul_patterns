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

typedef long long ll;
const int MOD = 998244353;
const int MAXN = 100005;
const int MAXV = 201;

ll dp[MAXN][MAXV];
int a[MAXN];
int n;

int main(){
    ((void)0);
    ((void)0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int first = a[1] == -1 ? 1 : a[1], last = a[n] == -1 ? 200 : a[n];
    for(int i=first;i<=last;i++){
        dp[1][i] = 1;
    }
    for(int i=2;i<=n;i++){
        int val = a[i];
        if(val != -1){
            for(int j=max(1,val-1);j<=min(MAXV-1,val+1);j++){
                (dp[i][val] += dp[i-1][j]) %= MOD;
            }
        }
        else{
            for(int j=1;j<=MAXV;j++){
                dp[i][j] = 0;
                for(int k=max(1,j-1);k<=min(MAXV-1,j+1);k++){
                    (dp[i][j] += dp[i-1][k]) %= MOD;
                }
            }
        }
    }
    ll ans = 0;
    int final_val = a[n] == -1 ? 200 : a[n];
    for(int i=max(1,final_val-1);i<=min(MAXV-1,final_val+1);i++){
        (ans += dp[n][i]) %= MOD;
    }
    cout << ans << "\n";
    return 0;
}