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
    long long X, K;
    cin >> X >> K;
    vector<long long> r(K);
    for(auto &x: r) cin >> x;
    long long Q;
    cin >> Q;
    vector<pair<long long, long long>> queries(Q);
    for(auto &x: queries) cin >> x.first >> x.second;
    r.push_back(1e18);
    int pos = 0;
    for(int i = 0; i < Q; i++){
        long long t = queries[i].first;
        long long a = queries[i].second;
        while(pos < K && r[pos] <= t){
            if(pos%2 == 0) a = max(0LL, a - (r[pos] - (pos == 0 ? 0 : r[pos-1])));
            else a = min(X, a + (r[pos] - (pos == 0 ? 0 : r[pos-1])));
            pos++;
        }
        if(pos%2 == 0) a = max(0LL, a - (t - (pos == 0 ? 0 : r[pos-1])));
        else a = min(X, a + (t - (pos == 0 ? 0 : r[pos-1])));
        cout << a << "\n";
    }
}