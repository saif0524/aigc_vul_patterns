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
    vector<long long> s(n);
    for(auto &x: s) { cin >> x; }
    vector<int> p(n);
    vector<bool> used(n+1, false);
    for(int i = 0; i < n; ++i){
        long long cur_sum = 0;
        for(int j = 1; j <= n; ++j){
            if(used[j]) continue;
            if(cur_sum + j == s[i]){
                p[i] = j;
                used[j] = true;
                break;
            }
            cur_sum += j;
        }
    }
    for(auto &x: p) { cout << x << " "; }
    cout << "\n";
}