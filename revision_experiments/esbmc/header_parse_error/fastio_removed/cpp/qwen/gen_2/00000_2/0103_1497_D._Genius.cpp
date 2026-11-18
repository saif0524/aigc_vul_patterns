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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> tags(n);
        vector<long long> scores(n);
        for(int i=0;i<n;i++) cin >> tags[i];
        for(int i=0;i<n;i++) cin >> scores[i];
        vector<vector<long long>> dp(n, vector<long long>(1<<16, LLONG_MIN));
        for(int i=0;i<n;i++){
            dp[i][1<<tags[i]] = scores[i];
        }
        long long ans = 0;
        for(int i=0;i<n;i++){
            for(int mask=0;mask<(1<<16);mask++){
                if(dp[i][mask] == LLONG_MIN) continue;
                for(int j=0;j<n;j++){
                    if(tags[i] != tags[j]){
                        int new_mask = mask | (1<<tags[j]);
                        long long new_iq = abs((1LL<<i) - (1LL<<j));
                        if(new_iq < (1<<16)){
                            dp[j][new_mask] = max(dp[j][new_mask], dp[i][mask] + abs(scores[i] - scores[j]));
                            ans = max(ans, dp[j][new_mask]);
                        }
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}