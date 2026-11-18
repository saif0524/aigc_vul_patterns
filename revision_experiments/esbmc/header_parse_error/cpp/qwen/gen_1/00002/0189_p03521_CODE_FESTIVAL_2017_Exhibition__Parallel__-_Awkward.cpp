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

const int MOD = 1e9 + 7;
const int MAXN = 2010;

int dp[MAXN][MAXN];
vector<int> adj[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i=2;i<=N;i++){
        int b;
        cin >> b;
        adj[b].push_back(i);
    }
    dp[0][0] = 1;
    for(int i=1;i<=N;i++){
        for(int mask=0;mask<(1<<N);mask++){
            if(dp[i-1][mask]){
                int j = __builtin_popcount(mask) + 1;
                for(int k=0;k<N;k++){
                    if(((mask>>k)&1)==0){
                        int new_mask = mask|(1<<k);
                        bool valid = true;
                        for(int &u : adj[j]){
                            if(((new_mask>>(u-1))&1)){
                                valid = false;
                            }
                        }
                        if(valid){
                            dp[i][new_mask] = (dp[i][new_mask] + dp[i-1][mask]) % MOD;
                        }
                    }
                }
            }
        }
    }
    cout << dp[N][(1<<N)-1] << "\n";
    return 0;
}