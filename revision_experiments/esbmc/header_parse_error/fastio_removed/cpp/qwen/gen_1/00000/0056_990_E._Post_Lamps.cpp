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
    int n, m, k;
    cin >> n >> m >> k;
    set<int> blocked;
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        blocked.insert(x);
    }
    vector<long long> a(k);
    for(auto &x: a) cin >> x;
    long long ans = LLONG_MAX;
    for(int l=1;l<=k;l++){
        long long cost = 0;
        int pos = 0;
        bool can = true;
        while(pos < n){
            int farthest = pos;
            for(int p = pos; p < min(n, pos + l + 1); p++){
                if(blocked.find(p) == blocked.end()){
                    farthest = p;
                }
            }
            if(farthest == pos){
                can = false;
                break;
            }
            cost += a[l-1];
            pos = farthest + 1;
        }
        if(can){
            ans = min(ans, cost);
        }
    }
    if(ans == LLONG_MAX){
        cout << -1;
    }
    else{
        cout << ans;
    }
    return 0;
}