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
    int n, m;
    cin >> n >> m;
    vector<vector<double>> plants(m);
    for(int i=0; i<n; i++){
        int s;
        double x;
        cin >> s >> x;
        plants[s-1].push_back(x);
    }
    vector<int> dp(m, 1e9);
    dp[0] = 0;
    for(int i=1; i<m; i++){
        vector<int> new_dp(m, 1e9);
        for(int j=0; j<i; j++){
            int need = dp[j] + (int) plants[i].size() - (int) (upper_bound(plants[j].begin(), plants[j].end(), plants[i].back()) - plants[j].begin());
            new_dp[i] = min(new_dp[i], need);
        }
        for(int j=0; j<=i; j++){
            if(i != j){
                new_dp[j] = min(new_dp[j], dp[j] + (int) plants[i].size());
            }
        }
        dp = new_dp;
    }
    int ans = *min_element(dp.begin(), dp.end());
    cout << ans;
}