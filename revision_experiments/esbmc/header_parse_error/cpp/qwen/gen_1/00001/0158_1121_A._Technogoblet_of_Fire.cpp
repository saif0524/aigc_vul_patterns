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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> power(n);
    for(auto &x: power) cin >> x;
    vector<int> school(n);
    for(auto &x: school) cin >> x;
    vector<int> chosen(k);
    for(auto &x: chosen) --x, cin >> x;

    vector<int> max_power_in_school(m, 0);
    for(int i = 0; i < n; ++i){
        max_power_in_school[school[i] - 1] = max(max_power_in_school[school[i] - 1], power[i]);
    }
    int ans = 0;
    for(auto &c: chosen){
        if(power[c] != max_power_in_school[school[c] - 1])
            ++ans;
    }
    cout << ans;
}