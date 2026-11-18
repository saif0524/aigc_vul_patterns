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
    for(int &x: a) { cin >> x; }
    vector<vector<int>> pos(n+1);
    for(int i=0;i<n;i++) pos[a[i]].push_back(i);
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(pos[i].size() < 2) continue;
        int f = 1;
        deque<int> q;
        for(int idx: pos[i]){
            while(!q.empty() && q.front() < idx - f) q.pop_front();
            if(!q.empty()){
                ans = max(ans, idx - q.front() + f);
            }
            while(!q.empty() && idx - q.back() <= f) q.pop_back();
            q.push_back(idx);
            if(q.size() >= 2) ans = max(ans, f*2);
            if(q.size() >= 3) q.pop_front();
            f++;
        }
    }
    cout << ans;
}