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
    int n, q;
    cin >> n >> q;
    vector<int> freq(31, 0);
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        int p = 0;
        while((1<<p) < x) p++;
        freq[p]++;
    }
    vector<int> dp(1<<16, -1);
    dp[0] = 0;
    for(int mask=0; mask<(1<<15); mask++){
        if(dp[mask] != -1){
            for(int i=0; i<15; i++){
                if(freq[i] > 0 && (mask & (1<<i)) == 0){
                    int nmask = mask | (1<<i);
                    if(dp[nmask] == -1 || dp[nmask] > dp[mask] + 1){
                        dp[nmask] = dp[mask] + 1;
                    }
                }
            }
        }
    }
    while(q--){
        int b;
        cin >> b;
        vector<int> used(15, 0);
        int sum = 0;
        for(int i=0; i<15; i++){
            if(b & (1<<i)){
                sum += min(freq[i], 1);
            }
        }
        int remaining = b;
        int needed = 0;
        for(int i=14; i>=0; i--){
            if(remaining & (1<<i)){
                if(dp[remaining] != -1){
                    needed = dp[remaining];
                    break;
                }
            }
        }
        if(needed == -1 || sum + needed > freq[i]){
            cout << -1 << "\n";
        } else {
            cout << sum + needed << "\n";
        }
    }
}