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
    long long n, sx, sy;
    cin >> n >> sx >> sy;
    vector<pair<long long, long long>> pos(n);
    map<pair<long long, long long>, long long> cnt;
    for(auto& [x,y] : pos){
        cin >> x >> y;
        cnt[{x,y}]++;
    }
    set<long long> X, Y;
    for(auto& [x,y] : pos){
        X.insert(x);
        Y.insert(y);
    }
    X.insert(sx);
    Y.insert(sy);
    X.erase(sx);
    Y.erase(sy);
    long long ans = 0;
    pair<long long, long long> best;
    for(long long x : X){
        for(long long y : Y){
            long long cur = 0;
            for(auto& [px, py] : cnt){
                if(abs(sx-x)+abs(sy-y) == abs(px-x)+abs(py-y) + abs(sx-px) + abs(sy-py)){
                    cur += cnt[{px, py}];
                }
            }
            if(cur > ans){
                ans = cur;
                best = {x, y};
            }
        }
    }
    cout << ans << "\n" << best.first << " " << best.second;
}