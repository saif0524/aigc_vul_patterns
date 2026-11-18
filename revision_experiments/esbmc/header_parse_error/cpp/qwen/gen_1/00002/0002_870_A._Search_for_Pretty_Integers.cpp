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
    int n, m;
    cin >> n >> m;
    set<int> a, b;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        a.insert(x);
    }
    for(int i=0; i<m; ++i){
        int x;
        cin >> x;
        b.insert(x);
    }
    if(!a.empty() && !b.empty()){
        int min_a = *min_element(a.begin(), a.end());
        int min_b = *min_element(b.begin(), b.end());
        int ans = min(min_a, min_b) * 10 + max(min_a, min_b);
        if(a.find(min_b) != a.end() || b.find(min_a) != b.end()){
            ans = min(ans, min(min_a, min_b));
        }
        cout << ans;
    }
}