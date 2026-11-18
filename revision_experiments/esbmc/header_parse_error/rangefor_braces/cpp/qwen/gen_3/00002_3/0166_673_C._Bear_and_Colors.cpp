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
    int n;
    cin >> n;
    vector<int> t(n);
    for(int &x : t) { cin >> x; }
    vector<int> ans(n, 0);
    for(int i = 0; i < n; ++i){
        vector<int> cnt(n+1, 0);
        int mx = 0;
        for(int j = i; j < n; ++j){
            ++cnt[t[j]];
            mx = max(mx, cnt[t[j]]);
            if(cnt[t[j]] == mx) ans[t[j]-1] += (j-i+1) - (mx - cnt[t[j]]);
        }
    }
    for(int i = 0; i < n; ++i) cout << ans[i] << (i == n-1 ? '\n' : ' ');
}