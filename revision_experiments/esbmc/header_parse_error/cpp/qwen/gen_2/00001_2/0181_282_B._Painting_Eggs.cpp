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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> eggs(n);
    for(auto &e: eggs){
        cin >> e.first >> e.second;
    }
    int total = 500 * n;
    vector<int> dp(total + 1, -1);
    dp[0] = 0;
    for(int i = 0; i < n; ++i){
        vector<int> ndp(dp);
        for(int j = 0; j <= total; ++j){
            if(dp[j] != -1){
                int takeA = j + eggs[i].first;
                int takeG = j - eggs[i].second;
                if(takeA <= total) ndp[takeA] = dp[j] | (1 << i);
                if(takeG >= 0) ndp[takeG] = dp[j] | (1 << i);
            }
        }
        dp = ndp;
    }
    int target = 500 * n;
    for(int i = max(0, target - 500); i <= min(total, target + 500); ++i){
        if(dp[i] != -1){
            string res(n, 'G');
            int mask = dp[i];
            for(int j = 0; j < n; ++j){
                if(mask & (1 << j)){
                    res[j] = 'A';
                }
            }
            cout << res << "\n";
            return 0;
        }
    }
    cout << "-1\n";
}