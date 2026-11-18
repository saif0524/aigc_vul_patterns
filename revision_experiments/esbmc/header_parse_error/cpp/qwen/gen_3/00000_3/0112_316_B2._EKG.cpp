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
    int n, x;
    cin >> n >> x;
    vector<int> a(n+1);
    for(int i=1; i<=n; ++i){
        cin >> a[i];
    }
    vector<bool> can_be_last(n+1, true);
    for(int i=1; i<=n; ++i){
        if(a[i] != 0){
            can_be_last[a[i]] = false;
        }
    }
    vector<int> result;
    for(int i=1; i<=n; ++i){
        if(can_be_last[i]){
            result.push_back(i);
        }
    }
    set<int> positions;
    function<void(int)> dfs = [&](int pos){
        positions.insert(pos);
        if(a[pos] == x){
            return;
        }
        if(a[pos] != 0){
            dfs(a[pos]);
        }
    };
    for(auto last : result){
        dfs(last);
    }
    for(auto pos : positions){
        cout << pos << "\n";
    }
}