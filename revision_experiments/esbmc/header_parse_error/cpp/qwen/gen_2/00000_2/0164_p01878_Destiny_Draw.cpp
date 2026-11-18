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

int main(){
    int N, K, C, T;
    cin >> N >> K >> C >> T;
    vector<vector<int>> shuffles(K, vector<int>(3));
    for(int i = 0; i < K; ++i){
        cin >> shuffles[i][0] >> shuffles[i][1] >> shuffles[i][2];
    }

    vector<vector<int>> dp(T+1, vector<int>(N+1, 0));
    dp[0][1] = 1;

    for(int t = 1; t <= T; ++t){
        for(int k = 0; k < K; ++k){
            int a = shuffles[k][0];
            int b = shuffles[k][1];
            int time = shuffles[k][2];
            if(t >= time){
                for(int card = 1; card <= N; ++card){
                    int new_pos = (card >= a && card < a + b) ? a : card;
                    if(card >= a && card < a + b){
                        new_pos = a;
                    }else if(card == a){
                        new_pos = a + b - 1;
                    }
                    dp[t][new_pos] = (dp[t][new_pos] + dp[t-time][card]) % MOD;
                }
            }
        }
    }
    cout << dp[T][C] << "\n";
    return 0;
}