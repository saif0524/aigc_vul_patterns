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
    int la, lb;
    cin >> la >> lb;
    vector<int> a(la), b(lb);
    for(auto &x: a) { cin >> x; }
    for(auto &x: b) { cin >> x; }
    int ans = 0;
    for(int shift=0; shift<la; shift++){
        int cnt = 0, j = 0;
        for(int i=0; i<la; i++){
            int cur = a[(i+shift)%la];
            while(j < lb && b[j] != cur) j++;
            if(j == lb) break;
            cnt++, j++;
        }
        ans = max(ans, cnt);
    }
    for(int shift=0; shift<lb; shift++){
        int cnt = 0, j = 0;
        for(int i=0; i<lb; i++){
            int cur = b[(i+shift)%lb];
            while(j < la && a[j] != cur) j++;
            if(j == la) break;
            cnt++, j++;
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}