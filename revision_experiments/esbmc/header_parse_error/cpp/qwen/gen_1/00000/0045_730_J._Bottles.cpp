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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    
    vector<pair<int, int>> ab(n);
    for(int i=0;i<n;i++) ab[i] = {a[i], b[i]};
    
    sort(ab.begin(), ab.end(), [&](auto &x, auto &y){
        return x.second - x.first > y.second - y.first;
    });
    
    priority_queue<int> pq;
    int time = 0, used = 0;
    
    for(auto &[ai, bi]: ab){
        int space = bi - ai;
        while(!pq.empty() && space > 0){
            int x = min(space, -pq.top());
            time += x;
            space -= x;
            int y = pq.top(); pq.pop();
            y += x;
            if(y < 0) pq.push(y);
        }
        if(space > 0){
            pq.push(-space);
            used++;
        }
    }
    
    cout << used + pq.size() << " " << time;
}