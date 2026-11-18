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
    vector<vector<char>> hex(n, vector<char>(n/4));
    for(int i=0;i<n;i++){
        for(int j=0;j<n/4;j++){
            cin >> hex[i][j];
        }
    }
    auto check = [&](int x){
        map<pair<int,int>, set<char>> m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n/4;j++){
                int row = i / x;
                int col = j / x;
                m[{row, col}].insert(hex[i][j]);
            }
        }
        for(auto &[p, s] : m){
            if(s.size() != 1) return false;
        }
        return true;
    };
    int ans = 1;
    for(int i=2;i<=n;i++){
        if(n % i == 0 && check(i)){
            ans = i;
        }
    }
    cout << ans;
}