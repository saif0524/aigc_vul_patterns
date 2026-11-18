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
    int n, p;
    cin >> n >> p;
    vector<vector<int>> opinions(n);
    for(int i=0; i<n; ++i){
        int x, y;
        cin >> x >> y;
        opinions[i] = {x-1, y-1};
    }
    long long ans = 0;
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            int cnt = 0;
            for(const auto& opinion : opinions){
                if(opinion[0] == i || opinion[1] == i || opinion[0] == j || opinion[1] == j){
                    cnt++;
                }
            }
            if(cnt >= p){
                ans++;
            }
        }
    }
    cout << ans;
}