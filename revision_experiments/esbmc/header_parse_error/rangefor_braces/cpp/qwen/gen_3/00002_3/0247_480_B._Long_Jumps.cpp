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
    int n, x, y;
    long long l;
    cin >> n >> l >> x >> y;
    vector<long long> a(n);
    for(auto &ai : a) { cin >> ai; }
    set<long long> s(a.begin(), a.end());
    int ans = 0;
    vector<long long> to_add;
    if(s.find(x) == s.end()){
        ++ans;
        to_add.push_back(x);
    }
    if(s.find(y) == s.end()){
        ++ans;
        to_add.push_back(y);
    }
    cout << ans << "\n";
    for(auto &ai : to_add) { cout << ai << " "; }
    cout << "\n";
}