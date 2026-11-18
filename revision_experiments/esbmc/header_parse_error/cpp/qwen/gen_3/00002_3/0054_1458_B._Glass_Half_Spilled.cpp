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
    vector<pair<int,int>> glasses(n);
    for(auto &g: glasses) cin >> g.first >> g.second;
    sort(glasses.begin(), glasses.end(), [](const pair<int,int>& a, const pair<int,int>& b){
        return (a.first - a.second) > (b.first - b.second);
    });
    vector<double> dp(n+1, 0);
    for(int i=0; i<n; i++){
        for(int j=i; j>=1; j--){
            double transferable = min(glasses[i].second - dp[j], (dp[j-1] - dp[j])*2);
            dp[j] += transferable / 2;
        }
        dp[i+1] = dp[i] + glasses[i].second;
    }
    for(int i=1; i<=n; i++) cout << setprecision(10) << fixed << min(dp[i], (double)accumulate(glasses.begin(), glasses.end(), 0, [](double sum, const pair<int,int>& g){return sum + g.second;})) << " ";
}