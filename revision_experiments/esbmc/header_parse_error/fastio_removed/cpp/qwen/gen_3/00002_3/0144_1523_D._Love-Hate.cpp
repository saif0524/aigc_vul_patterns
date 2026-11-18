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
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> friends(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            if(c == '1'){
                friends[i] |= (1<<j);
            }
        }
    }
    int half = (n+1)/2;
    int max_set = 0;
    int result_mask = 0;
    for(int mask = 0; mask < (1<<m); mask++){
        int count = 0;
        for(int friend_mask : friends){
            if(__builtin_popcount(mask & friend_mask) == __builtin_popcount(mask)){
                count++;
            }
        }
        if(count >= half){
            int set_size = __builtin_popcount(mask);
            if(set_size > max_set){
                max_set = set_size;
                result_mask = mask;
            }
        }
    }
    for(int j = 0; j < m; j++){
        if(result_mask & (1<<j)){
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << "\n";
}