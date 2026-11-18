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
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for(int &x : a) { cin >> x; }
    for(int &x : b) { cin >> x; }
    for(int &x : c) { cin >> x; }
    set<int> all;
    for(int x : a) { all.insert(x); }
    for(int x : b) { all.insert(x); }
    for(int x : c) { all.insert(x); }
    map<int, int> mp;
    for(int x : all) { mp[x] = mp.size(); }
    vector<int> freq(mp.size(), 0);
    for(int x : a) { freq[mp[x]]++; }
    for(int x : b) { freq[mp[x]]++; }
    for(int x : c) { freq[mp[x]]++; }
    vector<int> count_a(mp.size(), 0), count_b(mp.size(), 0), count_c(mp.size(), 0);
    for(int i = 0; i < n; ++i){
        count_a[mp[a[i]]]++;
        count_b[mp[b[i]]]++;
        count_c[mp[c[i]]]++;
    }
    vector<int> need(mp.size(), 0);
    for(int i = 0; i < mp.size(); ++i){
        need[i] = freq[i] - (count_a[i] > 0) - (count_b[i] > 0) - (count_c[i] > 0);
    }
    int res = 3 * n;
    vector<vector<int>> dp(2, vector<int>(mp.size() + 1, n));
    dp[0][0] = 0;
    for(int type = 0; type < 3; ++type){
        vector<int> &cur = (type == 0 ? count_a : (type == 1 ? count_b : count_c));
        fill(dp[(type + 1) % 2].begin(), dp[(type + 1) % 2].end(), n);
        int need_cover = 0;
        for(int j = 0; j < mp.size(); ++j) need_cover += (need[j] > 0);
        int have = 0, j = 0;
        for(int i = 0; i <= n; ++i){
            while(j < mp.size() && have < need_cover){
                if(cur[j] > 0) have++;
                j++;
            }
            dp[(type + 1) % 2][j] = min(dp[(type + 1) % 2][j], dp[type % 2][i] + n - j);
            dp[(type + 1) % 2][j - 1] = min(dp[(type + 1) % 2][j - 1], dp[type % 2][i] + n - (j - 1));
            if(j > 0 && cur[j - 1] > 0) have--;
        }
    }
    for(int i = 0; i <= n; ++i) res = min(res, dp[0][i]);
    cout << res;
}