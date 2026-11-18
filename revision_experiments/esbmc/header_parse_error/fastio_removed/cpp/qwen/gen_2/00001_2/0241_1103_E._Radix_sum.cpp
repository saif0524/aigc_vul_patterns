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

typedef unsigned long long ull;

const ull MOD = (1ULL << 58);

ull dp[100001][10];

int main(){
    ((void)0);
    ((void)0);
    int n;
    cin >> n;
    vector<int> x(n);
    for(auto &i : x) cin >> i;
    for(int i=0;i<10;i++) dp[0][i]=0;
    for(int i=0;i<n;i++){
        int d=0;
        while(x[i]){
            dp[i+1][(d+x[i]%10)%10]+=1;
            dp[i+1][(d+x[i]%10)%10]%=MOD;
            d+=x[i]%10;
            d%=10;
            x[i]/=10;
        }
        for(int j=0;j<10;j++){
            dp[i+1][j]+=dp[i][j];
            dp[i+1][j]%=MOD;
        }
    }
    for(int i=0;i<n;i++){
        cout << dp[n][i] << (i==n-1?"\n":" ");
    }
}