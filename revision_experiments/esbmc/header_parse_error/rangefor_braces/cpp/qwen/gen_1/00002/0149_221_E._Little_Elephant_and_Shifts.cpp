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
    for(int &x: a) { cin >> x; }
    for(int &x: b) { cin >> x; }
    map<int, vector<int>> pos_a;
    for(int i=0; i<n; ++i) pos_a[a[i]].push_back(i);
    vector<int> ans(n, n);
    for(int i=0; i<n; ++i){
        for(int x: pos_a[b[i]]){
            ans[i] = min(ans[i], abs(x - i));
            ans[(i-x+n)%n] = min(ans[(i-x+n)%n], abs(x - i));
        }
    }
    for(int x: ans) { cout << x << '\n'; }
}