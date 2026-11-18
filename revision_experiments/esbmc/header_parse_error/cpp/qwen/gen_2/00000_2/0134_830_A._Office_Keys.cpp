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
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> a(n), b(k);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<n;i++){
        int best = 1e9+7;
        int loc = a[i];
        int idx = lower_bound(b.begin(), b.end(), loc) - b.begin();
        if(idx < k){
            best = min(best, abs(loc-b[idx])+abs(p-b[idx]));
        }
        if(idx > 0){
            best = min(best, abs(loc-b[idx-1])+abs(p-b[idx-1]));
        }
        pq.push(best);
    }
    int ans = 0;
    while(n--){
        ans = max(ans, pq.top());
        pq.pop();
    }
    cout << ans;
}