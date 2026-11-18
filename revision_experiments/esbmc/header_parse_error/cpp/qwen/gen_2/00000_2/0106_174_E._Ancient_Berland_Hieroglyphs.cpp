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
    int la, lb;
    cin >> la >> lb;
    vector<int> a(la), b(lb);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    unordered_map<int, vector<int>> pos_b;
    for(int i=0;i<lb;i++) pos_b[b[i]].push_back(i);
    int ans = 0;
    for(int shift=0;shift<la;shift++){
        int last = -1;
        int current_length = 0;
        for(int i=0;i<la;i++){
            int glyph = a[(i+shift)%la];
            if(pos_b.count(glyph)){
                auto it = upper_bound(pos_b[glyph].begin(), pos_b[glyph].end(), last);
                if(it != pos_b[glyph].end()){
                    last = *it;
                    current_length++;
                }
            }
            else{
                current_length = 0;
                last = -1;
            }
            ans = max(ans, current_length);
        }
    }
    cout << ans;
}