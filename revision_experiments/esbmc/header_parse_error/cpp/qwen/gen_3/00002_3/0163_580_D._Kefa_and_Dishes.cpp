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

typedef long long ll;

int n, m, k;
ll satisfaction[19];
vector<pair<int, ll>> rules[19];
ll dp[1 << 18], last[1 << 18];

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> satisfaction[i];
    for(int i = 0; i < k; i++){
        int x, y; ll c;
        cin >> x >> y >> c;
        x--, y--;
        rules[x].emplace_back(y, c);
    }
    for(int mask = 0; mask < (1 << n); mask++){
        if(__builtin_popcount(mask) > m) continue;
        for(int last_eaten = 0; last_eaten < n; last_eaten++){
            if(mask & (1 << last_eaten)){
                int prev_mask = mask ^ (1 << last_eaten);
                if(prev_mask == 0){
                    dp[mask] = max(dp[mask], satisfaction[last_eaten]);
                }
                else{
                    ll current_satisfaction = dp[prev_mask] + satisfaction[last_eaten];
                    for(auto [next, bonus] : rules[last_eaten]){
                        if(prev_mask & (1 << next)){
                            current_satisfaction += bonus;
                        }
                    }
                    dp[mask] = max(dp[mask], current_satisfaction);
                }
            }
        }
    }
    cout << dp[(1 << n) - 1] << "\n";
}