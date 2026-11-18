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
    int N, M;
    cin >> N >> M;
    vector<int> D(N);
    for(auto &d : D) cin >> d;
    vector<int> C(M);
    for(auto &c : C) cin >> c;
    
    vector<int> dp(N+1, 1e9);
    dp[0] = 0;
    for(int i = 0; i < N; i++){
        vector<int> new_dp(N+1, 1e9);
        for(int j = 0; j <= i; j++){
            int days_left = M - j;
            for(int k = 1; k <= days_left && i+k <= N; k++){
                new_dp[i+k] = min(new_dp[i+k], dp[j] + D[i] * C[j+k-1]);
            }
        }
        dp = move(new_dp);
    }
    cout << dp[N] << endl;
}