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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> tags(n), scores(n);
        for(int &x: tags) cin >> x;
        for(int &x: scores) cin >> x;
        vector<long long> dp(1<<13, -1LL);
        dp[0] = 0;
        for(int i=0; i<n; ++i){
            for(int mask=0; mask<(1<<13); ++mask){
                if(dp[mask] == -1) continue;
                for(int j=0; j<n; ++j){
                    if(i == j) continue;
                    if(tags[i] == tags[j]) continue;
                    int iq = abs((1<<i) - (1<<j));
                    if(iq <= mask) continue;
                    int new_mask = mask | (1<<iq);
                    dp[new_mask] = max(dp[new_mask], dp[mask] + abs(scores[i] - scores[j]));
                }
            }
        }
        cout << *max_element(dp.begin(), dp.end()) << "\n";
    }
}