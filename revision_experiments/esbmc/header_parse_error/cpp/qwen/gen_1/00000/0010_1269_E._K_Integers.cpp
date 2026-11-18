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
    int n;
    cin >> n;
    vector<int> p(n);
    for(auto &x: p) cin >> x;
    vector<long long> f(n + 1);
    for(int k = 1; k <= n; ++k){
        deque<int> dq;
        long long current = 0;
        for(int i = 0; i < k; ++i){
            while(!dq.empty() && p[i] < p[dq.back()]){
                current += i - dq.back();
                dq.pop_back();
            }
            dq.push_back(i);
        }
        f[k] = current;
        for(int i = k; i < n; ++i){
            if(dq.front() <= i - k){
                current -= dq.front() - (i - k);
                dq.pop_front();
            }
            while(!dq.empty() && p[i] < p[dq.back()]){
                current += i - dq.back();
                dq.pop_back();
            }
            dq.push_back(i);
            if(dq.front() == i - k + 1){
                current -= p[dq.front()] - p[i];
            }else{
                current += (i - (i - k + 1)) - (p[dq.front()] - p[i]);
            }
            f[k] = min(f[k], current);
        }
    }
    for(int k = 1; k <= n; ++k){
        cout << f[k] << " ";
    }
    return 0;
}