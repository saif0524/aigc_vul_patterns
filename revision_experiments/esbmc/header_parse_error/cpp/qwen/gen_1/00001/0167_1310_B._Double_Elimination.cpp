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
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for(auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    int ans = 0;
    for(auto x: a){
        set<int> played;
        int cur = x;
        int round = 0;
        while(round < n){
            int next = (cur & (cur + 1)) ? cur - (1 << __builtin_ctz(cur)) : cur + (1 << (n - round - 1));
            if(played.find(next) == played.end()){
                ans++;
                played.insert(next);
            }
            cur = (cur & (cur + 1)) ? cur - (1 << __builtin_ctz(cur)) : (cur >> (n - round));
            round++;
        }
        cur = x;
        round = 0;
        while(round < n-1){
            int next = cur + (1 << (n - round - 2));
            if(played.find(next) == played.end()){
                ans++;
                played.insert(next);
            }
            cur = cur + (1 << (n - round - 2));
            round++;
        }
    }
    cout << ans;
}