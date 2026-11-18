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
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<pair<int,int>> points(n);
        for(auto &p : points){
            cin >> p.first >> p.second;
        }
        int ans = INT_MAX;
        bool possible = false;
        for(int i = 0; i < n; ++i){
            int count = 0;
            for(int j = 0; j < n; ++j){
                if(abs(points[i].first - points[j].first) + abs(points[i].second - points[j].second) <= k){
                    count++;
                }
            }
            if(count > 1){
                ans = min(ans, n - count);
                possible = true;
            }
        }
        if(possible){
            cout << ans << "\n";
        }
        else{
            cout << "-1\n";
        }
    }
}