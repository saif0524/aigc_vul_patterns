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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<long long> dpX(n + 1, 0);
    dpX[0] = 1;
    for(int i = 1; i <= n; ++i){
        dpX[i] = (s[i-1] == 'X' ? dpX[i-1] * 2 % MOD : dpX[i-1]);
    }
    long long ans = 0;
    long long bPoss = 0;
    long long wPoss = 0;
    for(int i = k; i <= n; ++i){
        if(s[i-k] == 'B' || s[i-k] == 'X'){
            bPoss = (bPoss + dpX[i-k]) % MOD;
        }
        if(i - 2*k + 1 > 0){
            if(s[i-2*k] == 'B' || s[i-2*k] == 'X'){
                bPoss = (bPoss - dpX[i-2*k-1] + MOD) % MOD;
            }
            if(s[i-2*k] == 'W' || s[i-2*k] == 'X'){
                wPoss = (wPoss - dpX[i-2*k-1] + MOD) % MOD;
            }
        }
        if(s[i-k] == 'W' || s[i-k] == 'X'){
            wPoss = (wPoss + dpX[i-k]) % MOD;
        }
        ans = (ans + bPoss * wPoss % MOD * dpX[n-i] % MOD) % MOD;
    }
    cout << ans;
}