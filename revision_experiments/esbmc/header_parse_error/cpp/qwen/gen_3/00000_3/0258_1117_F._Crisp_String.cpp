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
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    vector<vector<int>> A(p, vector<int>(p));
    for(int i = 0; i < p; ++i){
        for(int j = 0; j < p; ++j){
            cin >> A[i][j];
        }
    }
    vector<int> cnt(26, 0);
    for(auto &c : s){
        cnt[c - 'a']++;
    }
    vector<int> dp(1 << p, n);
    dp[0] = 0;
    for(int mask = 0; mask < (1 << p); ++mask){
        for(int i = 0; i < p; ++i){
            if(cnt[i] == 0){
                continue;
            }
            if(mask & (1 << i)){
                continue;
            }
            int new_mask = mask | (1 << i);
            int can = 1;
            for(int j = 0; j < p; ++j){
                if((mask & (1 << j)) && !A[i][j]){
                    can = 0;
                    break;
                }
            }
            if(can){
                dp[new_mask] = min(dp[new_mask], dp[mask] - cnt[i]);
            }
        }
    }
    cout << dp[(1 << p) - 1] << "\n";
}