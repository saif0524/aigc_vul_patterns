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
    long long T, n;
    cin >> T >> n;
    vector<long long> a(n);
    for(auto &x: a) { cin >> x; }
    vector<long long> sum(n, 0);
    long long total = 0;
    for(int i=0; i<n; ++i){
        sum[i] = total;
        total += a[i];
    }
    vector<long long> cnt(n, 0);
    long long cycle = total;
    for(long long t=0; t<T; ++t){
        long long minT = LLONG_MAX, minIdx = -1;
        for(int i=0; i<n; ++i){
            long long requestTime = (t - sum[i] + cycle) % cycle;
            if(requestTime < minT){
                minT = requestTime;
                minIdx = i;
            }
        }
        cnt[minIdx]++;
    }
    for(long long x: cnt) { cout << x << " "; }
    cout << "\n";
}