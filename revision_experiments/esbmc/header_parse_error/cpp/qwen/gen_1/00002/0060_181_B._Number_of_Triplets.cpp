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
    vector<pair<int, int>> points(n);
    for(auto &p : points) cin >> p.first >> p.second;
    map<pair<int, int>, int> midpoint_count;
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            int x1 = points[i].first, y1 = points[i].second;
            int x2 = points[j].first, y2 = points[j].second;
            int xm = x1 + x2, ym = y1 + y2;
            if(xm % 2 == 0 && ym % 2 == 0){
                midpoint_count[{xm/2, ym/2}]++;
            }
        }
    }
    long long ans = 0;
    for(auto &[m, count] : midpoint_count){
        ans += (long long)count * (count - 1) / 2;
    }
    cout << ans;
}