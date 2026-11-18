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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int &x: a) cin >> x;
    for(int &x: b) cin >> x;
    vector<int> pos_a(n+1);
    for(int i=0; i<n; ++i) pos_a[a[i]] = i;
    vector<int> res(n, INT_MAX);
    vector<int> min_dist(n, INT_MAX);
    for(int i=0; i<n; ++i){
        int idx_a = pos_a[b[i]];
        int idx_b = i;
        for(int offset: {0, n}){
            int rel_pos = (idx_a - (idx_b + offset) + n) % n;
            min_dist[rel_pos] = min(min_dist[rel_pos], abs(idx_a - (idx_b + offset)));
        }
    }
    for(int i=0; i<n; ++i) res[(n-i)%n] = min_dist[i];
    for(int i=0; i<n; ++i) cout << res[i] << (i==n-1?'\n':' ');
}