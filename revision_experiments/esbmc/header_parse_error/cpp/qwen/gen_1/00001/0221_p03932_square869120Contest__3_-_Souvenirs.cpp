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
    int H, W;
    cin >> H >> W;
    vector<vector<int>> a(H, vector<int>(W));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> a[i][j];
        }
    }
    vector<vector<vector<long long>>> dp(H, vector<vector<long long>>(W, vector<long long>(1<<H, -1)));
    dp[0][0][1] = a[0][0];
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            for(int mask=0;mask<(1<<H);mask++){
                if(dp[i][j][mask] == -1) continue;
                if(i+1 < H){
                    dp[i+1][j][mask|(1<<(i+1))] = max(dp[i+1][j][mask|(1<<(i+1))], dp[i][j][mask] + a[i+1][j]);
                }
                if(j+1 < W){
                    dp[i][j+1][mask] = max(dp[i][j+1][mask], dp[i][j][mask] + a[i][j+1]);
                }
            }
        }
    }
    long long ans = 0;
    for(int mask=0;mask<(1<<H);mask++){
        ans = max(ans, dp[H-1][W-1][mask]);
    }
    cout << ans << endl;
}