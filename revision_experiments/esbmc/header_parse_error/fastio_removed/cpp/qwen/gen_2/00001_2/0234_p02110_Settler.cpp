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

typedef long long ll;
const int MAXN = 6005;

int N, K;
ll x[MAXN], y[MAXN];
vector<int> ans;

bool valid(int mask) {
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if((mask & (1 << i)) && (mask & (1 << j))){
                ll dx = x[i] - x[j];
                ll dy = y[i] - y[j];
                if(dx * dx + dy * dy < 4){
                    return false;
                }
            }
        }
    }
    return true;
}

int main(){
    ((void)0);
    ((void)0);
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        cin >> x[i] >> y[i];
    }
    int lim = 1 << N;
    int best_mask = -1;
    for(int mask = 0; mask < lim; mask++){
        if(__builtin_popcount(mask) == K && valid(mask)){
            if(best_mask == -1 || mask < best_mask){
                best_mask = mask;
            }
        }
    }
    if(best_mask == -1){
        cout << -1;
    } else {
        for(int i = 1; i <= N; i++){
            if(best_mask & (1 << i)){
                ans.push_back(i);
            }
        }
        for(int a : ans){
            cout << a << "\n";
        }
    }
}