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
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<pair<char, char>> forbidden(k);
    for(auto &it: forbidden){
        cin >> it.first >> it.second;
    }
    vector<int> dp(26, 0);
    for(auto c: s){
        int max_val = 0;
        for(auto &[a, b]: forbidden){
            if(a==c || b==c){
                continue;
            }
            max_val = max(max_val, dp[a-'a']);
            max_val = max(max_val, dp[b-'a']);
        }
        if(dp[c-'a'] < max_val + 1){
            dp[c-'a'] = max_val + 1;
        }
    }
    int max_val = 0;
    for(auto &it: dp){
        max_val = max(max_val, it);
    }
    cout << (int)s.length() - max_val;
}