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
        vector<long long> a(n);
        vector<pair<long long, long long>> ranges;
        long long last = -1;
        for(int i=0;i<n;i++){
            cin >> a[i];
            if(a[i] == -1){
                if(last != -1){
                    ranges.emplace_back(last, i);
                }
                last = i;
            }
        }
        ranges.emplace_back(last, n);
        if(ranges[0].first == 0){
            ranges.erase(ranges.begin());
        }
        if(ranges.back().second == n){
            ranges.pop_back();
        }
        long long min_diff = LLONG_MAX;
        long long best_k = 0;
        for(auto &[l, r] : ranges){
            if(r - l == 1){
                continue;
            }
            if(l == 0 || r == n){
                long long val = (l == 0) ? a[r] : a[l-1];
                long long diff = (r - l - 1) % 2 == 1 ? 1 : 0;
                if(min_diff > abs(val - a[l-diff])){
                    min_diff = abs(val - a[l-diff]);
                    best_k = val;
                }
                if(diff == 1){
                    long long k = (val + a[l-diff]) / 2;
                    long long upper_diff = max(abs(k - val), abs(k - a[l-diff]));
                    if(upper_diff < min_diff){
                        best_k = k;
                        min_diff = upper_diff;
                    }
                }
            }else{
                long long left_val = a[l-1];
                long long right_val = a[r];
                if(min_diff > abs(left_val - right_val)){
                    min_diff = abs(left_val - right_val);
                    best_k = (left_val + right_val) / 2;
                }
            }
        }
        for(int i=1;i<n-1;i++){
            if(a[i] != -1){
                continue;
            }
            long long possible_min = min(abs(a[i-1] - a[i+1]), min_diff);
            if(possible_min < min_diff){
                min_diff = possible_min;
                best_k = (a[i-1] + a[i+1]) / 2;
            }
        }
        cout << min_diff << " " << best_k << "\n";
    }
}