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
    vector<int> c(n*k), f(n), h(k);
    for(auto &x: c) cin >> x;
    for(auto &x: f) cin >> x;
    for(auto &x: h) cin >> x;
    
    sort(c.rbegin(), c.rend());
    map<int, int> freq;
    for(auto x: c) freq[x]++;
    
    vector<int> tar(n, k);
    for(auto &x: tar) cin >> x;
    int ans = 0;
    
    for(int i=0;i<n;i++){
        int need = tar[i];
        int joy = 0;
        for(int j=k-1;j>=0;j--){
            int cnt = min(freq[f[i]], need);
            freq[f[i]] -= cnt;
            joy += cnt * h[j];
            need -= cnt;
        }
        ans += joy;
    }
    
    cout << ans;
}