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
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    if(n == 1){
        cout << 0;
        return 0;
    }
    priority_queue<pair<int, pair<int, int>>> pq;
    for(int i=1; i<n-1; i++){
        pq.push({-min(a[i-1], a[i+1]), {i, i}});
    }
    vector<bool> removed(n, false);
    long long score = 0;
    while(!pq.empty()){
        auto t = pq.top();
        pq.pop();
        int i = t.second.first;
        int j = t.second.second;
        if(removed[i] || removed[j]) continue;
        score -= t.first;
        removed[i] = true;
        if(j > i+1 && !removed[j-1]){
            pq.push({-min(a[i-1], a[j-1]), {i, j-1}});
        }
        if(i-1 > j+1 && !removed[i-2]){
            pq.push({-min(a[j+1], a[i-2]), {j+1, i-1}});
        }
    }
    if(n > 2){
        score += min(a[0], a[1]);
        score += min(a[n-2], a[n-1]);
    }
    else{
        score += min(a[0], a[1]);
    }
    cout << score;
}