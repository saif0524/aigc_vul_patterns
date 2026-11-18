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
    long long T, n;
    cin >> T >> n;
    vector<long long> a(n);
    for(auto &x : a) { cin >> x; }
    vector<long long> sum(n);
    sum[0] = a[0];
    for(int i=1; i<n; i++) sum[i] = sum[i-1] + a[i];
    long long L = sum[n-1];
    vector<long long> res(n, 0);
    for(long long t=0; t<T; t++){
        int idx = 0;
        for(int i=1; i<n; i++){
            if(((t - sum[i] + L) % L) < ((t - sum[idx] + L) % L)) idx = i;
        }
        res[idx]++;
    }
    for(auto &x : res) { cout << x << " "; }
    cout << "\n";
}