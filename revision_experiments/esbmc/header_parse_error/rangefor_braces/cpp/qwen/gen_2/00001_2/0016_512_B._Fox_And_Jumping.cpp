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
    int n;
    cin >> n;
    vector<long long> lengths(n);
    vector<int> costs(n);
    for(auto &x: lengths) { cin >> x; }
    for(auto &x: costs) { cin >> x; }

    auto gcd = [](long long a, long long b){
        while(b){
            a %= b;
            swap(a, b);
        }
        return a;
    };

    int dp[100001] = {0};
    fill(dp, dp+100001, 1e9);
    dp[0] = 0;
    int max_cost = *max_element(costs.begin(), costs.end());
    for(int i=0; i<n; i++){
        vector<int> ndp(100001, 1e9);
        for(int mask=0; mask<(1<<n); mask++){
            int cost = 0;
            long long lcm = 1;
            bool valid = true;
            for(int j=0; j<n && valid; j++){
                if(mask & (1<<j)){
                    cost += costs[j];
                    if(dp[mask ^ (1<<j)] == 1e9){
                        valid = false;
                        break;
                    }
                    long long new_lcm = lcm ? (lcm / gcd(lcm, lengths[j])) * lengths[j] : lengths[j];
                    if(new_lcm <= 100000){
                        lcm = new_lcm;
                    } else {
                        valid = false;
                        break;
                    }
                }
            }
            if(valid){
                cost += dp[mask];
                ndp[cost] = min(ndp[cost], (int)lcm);
            }
        }
        for(int cost=0; cost<=max_cost; cost++){
            dp[cost] = min(dp[cost], ndp[cost]);
        }
    }

    int ans = -1;
    for(int cost=0; cost<=max_cost; cost++){
        if(dp[cost] == 1){
            ans = cost;
            break;
        }
    }
    cout << ans;
}