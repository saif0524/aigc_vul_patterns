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

const int MAXN = 1e6 + 10;

ll n, k, m;
vector<pair<int, int>> events[MAXN];
ll dp[MAXN];

int main(){
    ((void)0);
    ((void)0);
    cin >> n >> k >> m;
    for(int i=0; i<m; i++){
        int l, r, c, p;
        cin >> l >> r >> c >> p;
        events[l-1].emplace_back(c, -p);
        events[r].emplace_back(c, p);
    }
    for(int i=0; i<n; i++){
        ll avail = 0;
        for(auto &e : events[i]){
            if(e.second < 0){
                avail += e.first;
            }
            else{
                avail -= e.first;
            }
        }
        dp[i] = avail * (-events[i][0].second);
        if(i > 0){
            dp[i] = min(dp[i], dp[i-1] + max(0LL, k - avail) * (-events[i][0].second));
        }
    }
    cout << dp[n-1] << "\n";
}