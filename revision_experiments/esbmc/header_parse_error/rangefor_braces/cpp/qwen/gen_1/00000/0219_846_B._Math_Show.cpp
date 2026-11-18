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
    int n, k;
    long long M;
    cin >> n >> k >> M;
    vector<int> t(k);
    for(auto &x: t) { cin >> x; }
    
    vector<long long> dp(M+1, 0);
    
    for(int i=0; i<k; ++i){
        for(long long j=M; j>=t[i]; --j){
            dp[j] = max(dp[j], dp[j-t[i]] + 1);
        }
    }
    
    long long total_points = 0;
    for(int i=0; i<n; ++i){
        long long time_used = 0;
        int subtasks_done = 0;
        for(int j=0; j<k; ++j){
            if(time_used + t[j] <= M){
                time_used += t[j];
                subtasks_done++;
            }
        }
        total_points += subtasks_done;
        if(subtasks_done == k){
            total_points++;
        }
        M -= time_used;
    }
    
    long long max_points = total_points;
    for(long long j=0; j<=M; ++j){
        max_points = max(max_points, total_points - dp[j] + dp[M]);
    }
    
    cout << max_points;
}