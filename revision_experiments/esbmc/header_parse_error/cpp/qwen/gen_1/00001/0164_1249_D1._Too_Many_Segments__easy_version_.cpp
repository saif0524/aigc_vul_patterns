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
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> seg(n);
    for(auto &s: seg) cin >> s.first >> s.second;

    vector<int> to_remove;
    auto is_valid = [&](const vector<int> &remove) -> bool {
        vector<int> cnt(201, 0);
        for(int i=0; i<n; ++i){
            if(find(remove.begin(), remove.end(), i) != remove.end()) continue;
            for(int j=seg[i].first; j<=seg[i].second; ++j){
                cnt[j]++;
            }
        }
        for(int j=1; j<=200; ++j){
            if(cnt[j] > k) return false;
        }
        return true;
    };

    int min_remove = n;
    for(int mask=0; mask<(1<<n); ++mask){
        vector<int> current;
        for(int i=0; i<n; ++i){
            if(mask & (1<<i)) current.push_back(i);
        }
        if(is_valid(current) && current.size() < min_remove){
            min_remove = current.size();
            to_remove = current;
        }
    }

    cout << min_remove << '\n';
    for(auto idx: to_remove){
        cout << idx+1 << ' ';
    }
}