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
    ((void)0);
    ((void)0);
    long long N, L;
    cin >> N >> L;
    vector<pair<long long, long long>> intervals(N);
    for(auto& [l, r]: intervals) cin >> l >> r;
    sort(intervals.begin(), intervals.end());
    long long x = 0, y = 0;
    long long st = 0, ed = 0;
    for(int i = 0; i < N && ed < L; ++i){
        if(intervals[i].first > st) ++x, st = ed;
        ed = max(ed, intervals[i].second);
    }
    if(st < L) ++x;
    vector<int> dp(L + 1, 0);
    dp[0] = 1;
    for(auto& [l, r]: intervals){
        for(int i = L; i >= r; --i){
            dp[i] = max(dp[i], dp[i - (r - l)]);
        }
    }
    for(int i = 0; i <= L; ++i){
        if(dp[i] == 1){
            y = i;
            break;
        }
    }
    cout << x << " " << y;
}