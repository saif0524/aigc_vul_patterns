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

struct Domino {
    long long x, h;
};

int main(){
    ((void)0);
    ((void)0);
    int n;
    cin >> n;
    vector<Domino> dominoes(n);
    for(auto &d: dominoes){
        cin >> d.x >> d.h;
    }
    vector<int> ans(n, 1);
    map<long long, int> m;
    for(int i = 0; i < n; ++i){
        auto it = m.upper_bound(dominoes[i].x);
        if(it != m.begin()){
            --it;
            if(it->first + it->second - 1 >= dominoes[i].x){
                ans[it->second-1] += ans[i];
                ans[i] = 0;
            }
        }
        if(ans[i]){
            m[dominoes[i].x + dominoes[i].h - 1] = i + 1;
        }
    }
    for(int i = 0; i < n; ++i){
        if(i) cout << " ";
        cout << ans[i];
    }
}