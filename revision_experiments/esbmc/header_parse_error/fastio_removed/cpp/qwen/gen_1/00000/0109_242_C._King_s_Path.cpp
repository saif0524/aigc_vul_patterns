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
const int MAXN = 1e5 + 10;
const int MAXR = 1e9 + 10;

map<ll, vector<pair<ll, ll>>> allowed;
map<ll, set<ll>> unique_rows;
int n;
ll x0, y0, x1, y1;

int main(){
    ((void)0);
    ((void)0);
    cin >> x0 >> y0 >> x1 >> y1;
    cin >> n;
    for(int i = 0; i < n; i++){
        ll ri, ai, bi;
        cin >> ri >> ai >> bi;
        allowed[ri].emplace_back(ai, bi);
        unique_rows[ri].insert(ai);
        unique_rows[ri].insert(bi);
        unique_rows[ri].insert(ai - 1);
        unique_rows[ri].insert(bi + 1);
    }
    for(auto& [row, segs]: allowed){
        sort(segs.begin(), segs.end());
        vector<ll> compress(unique_rows[row].begin(), unique_rows[row].end());
        compress.erase(unique(compress.begin(), compress.end()), compress.end());
        map<ll, ll> compress_map;
        for(int i = 0; i < compress.size(); i++){
            compress_map[compress[i]] = i;
        }
        vector<int> dp(compress.size(), 1e9);
        for(auto& [l, r]: segs){
            for(int j = compress_map[l]; j <= compress_map[r]; j++){
                dp[j] = 0;
            }
        }
        for(auto& [l, r]: segs){
            int left = compress_map[l - 1], right = compress_map[r + 1];
            for(int j = compress_map[l]; j <= compress_map[r]; j++){
                if(j > 0){
                    dp[j] = min(dp[j], dp[j - 1] + 1);
                }
                if(j + 1 < compress.size()){
                    dp[j] = min(dp[j], dp[j + 1] + 1);
                }
                if(left >= 0){
                    dp[j] = min(dp[j], dp[left] + 1);
                }
                if(right < compress.size()){
                    dp[j] = min(dp[j], dp[right] + 1);
                }
            }
        }
        for(auto& [l, r]: segs){
            for(int j = compress_map[l]; j <= compress_map[r]; j++){
                if(j > 0){
                    dp[j - 1] = min(dp[j - 1], dp[j] + 1);
                }
                if(j + 1 < compress.size()){
                    dp[j + 1] = min(dp[j + 1], dp[j] + 1);
                }
                if(left >= 0){
                    dp[left] = min(dp[left], dp[j] + 1);
                }
                if(right < compress.size()){
                    dp[right] = min(dp[right], dp[j] + 1);
                }
            }
        }
        allowed[row] = {{compress[0], compress.back()}};
        for(int j = 1; j < compress.size(); j++){
            if(dp[j] == 1e9){
                allowed[row].back().second = compress[j - 1];
                allowed[row].emplace_back(compress[j], compress[j]);
            }
        }
        allowed[row].back().second = compress.back();
    }
    set<pair<ll, ll>> pq;
    map<ll, int> min_dist;
    pq.emplace(0, x0);
    min_dist[x0] = 0;
    while(!pq.empty()){
        auto [dist, row] = *pq.begin();
        pq.erase(pq.begin());
        if(row == x1){
            for(auto [l, r]: allowed[row]){
                if(l <= y1 && y1 <= r){
                    cout << dist + abs(row - x0) + abs(y1 - y0);
                    return 0;
                }
            }
        }
        if(allowed.count(row - 1)){
            for(auto [l, r]: allowed[row - 1]){
                if(l <= y0 && y0 <= r){
                    for(auto [nl, nr]: allowed[row - 1]){
                        if(min_dist.count(row - 1) == 0 || min_dist[row - 1] > dist + 1){
                            min_dist[row - 1] = dist + 1;
                            pq.emplace(dist + 1, row - 1);
                        }
                    }
                }
            }
        }
        if(allowed.count(row + 1)){
            for(auto [l, r]: allowed[row + 1]){
                if(l <= y0 && y0 <= r){
                    for(auto [nl, nr]: allowed[row + 1]){
                        if(min_dist.count(row + 1) == 0 || min_dist[row + 1] > dist + 1){
                            min_dist[row + 1] = dist + 1;
                            pq.emplace(dist + 1, row + 1);
                        }
                    }
                }
            }
        }
    }
    cout << -1;
}