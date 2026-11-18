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
    vector<pair<long long, long long>> trees(n);
    for(auto &tree : trees){
        cin >> tree.first >> tree.second;
    }
    set<long long> occupied;
    for(long long x : {-1e9, 1e9}) occupied.insert(x);
    int ans = 0;
    for(auto [x, h] : trees){
        long long left = x - h, right = x + h;
        auto it = occupied.lower_bound(x);
        long long right_next = *it;
        long long left_prev = *(--it);
        if(right_next > right){
            occupied.insert(right);
            ans++;
        }
        else if(left_prev < left){
            occupied.insert(left);
            ans++;
        }
    }
    cout << ans;
}