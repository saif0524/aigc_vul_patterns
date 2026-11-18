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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n);
        for(auto &x: a) cin >> x;
        vector<pair<long long,long long>> segs;
        int miss = 0;
        for(int i = 0; i < n; ++i){
            if(a[i] == -1){
                while(i < n && a[i] == -1){
                    ++miss;
                    ++i;
                }
                segs.emplace_back(a[i - miss - 1], a[i]);
            }
        }
        long long m = 1e18, k = 0;
        for(auto [l, r]: segs){
            if(l > r) swap(l, r);
            long long diff = abs(l - r);
            long long mm = (diff + miss - 1) / miss;
            if(mm < m){
                m = mm;
                k = (l + r) / 2;
            }
            else if(mm == m){
                k = min(k, (l + r) / 2);
            }
        }
        cout << m << " " << k << "\n";
    }
}