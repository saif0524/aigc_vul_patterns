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
    long long m;
    cin >> n >> m;
    vector<long long> a(n), b(n);
    for(auto &x: a) { cin >> x; }
    for(auto &x: b) { cin >> x; }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long x = -1;
    for(int i=0; i<n; ++i){
        long long diff = (b[i] - a[i] + m) % m;
        if(x == -1) x = diff;
        if((a[i] + x) % m != b[i]){
            cout << "-1";
            return 0;
        }
    }
    cout << x;
}