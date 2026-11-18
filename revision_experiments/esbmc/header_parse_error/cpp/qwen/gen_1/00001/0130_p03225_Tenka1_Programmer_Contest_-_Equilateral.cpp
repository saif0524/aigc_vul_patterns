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
    int H, W;
    cin >> H >> W;
    vector<vector<bool>> grid(H, vector<bool>(W, false));
    for(int i = 0; i < H; ++i){
        string s;
        cin >> s;
        for(int j = 0; j < W; ++j){
            grid[i][j] = (s[j] == '#');
        }
    }
    vector<pair<int, int>> coins;
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            if(grid[i][j]){
                coins.emplace_back(i, j);
            }
        }
    }
    int n = coins.size();
    map<int, vector<pair<int, int>>> dist_map;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            int dist = abs(coins[i].first - coins[j].first) + abs(coins[i].second - coins[j].second);
            dist_map[dist].emplace_back(i, j);
        }
    }
    long long ans = 0;
    for(const auto& [dist, pairs] : dist_map){
        map<int, int> count;
        for(const auto& [a, b] : pairs){
            count[a]++;
            count[b]++;
        }
        for(const auto& [a, cnt] : count){
            long long x = cnt;
            ans += (x * (x - 1) / 2) * (n - cnt);
        }
    }
    cout << ans / 3 << endl;
}