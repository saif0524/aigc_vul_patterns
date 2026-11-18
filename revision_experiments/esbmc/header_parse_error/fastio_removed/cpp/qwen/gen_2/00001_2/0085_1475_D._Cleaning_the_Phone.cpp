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
    int t;
    cin >> t;
    while(t--){
        long long n, m;
        cin >> n >> m;
        vector<long long> a(n), b(n);
        for(auto &i : a) cin >> i;
        for(auto &i : b) cin >> i;
        vector<pair<long long, long long>> apps(n);
        for(int i = 0; i < n; ++i){
            apps[i] = {a[i], b[i]};
        }
        sort(apps.begin(), apps.end(), [&](auto &p1, auto &p2){
            return p1.first > p2.first;
        });
        long long max_convenience = 0;
        for(auto &p : apps){
            max_convenience += p.second;
        }
        vector<long long> psum(n + 1, 0);
        for(int i = 1; i <= n; ++i){
            psum[i] = psum[i - 1] + apps[i - 1].second;
        }
        long long minloss = -1;
        long long left = 0, right = 0, currentsum = 0;
        while(left <= right && right <= n){
            if(currentsum >= m){
                minloss = min(minloss, max_convenience - psum[left] + psum[right]);
                currentsum -= apps[left++].first;
            }
            else{
                if(right < n) currentsum += apps[right++].first;
                else break;
            }
        }
        cout << minloss << "\n";
    }
}