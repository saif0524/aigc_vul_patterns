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
    vector<pair<int, int>> v;
    for(int i=0; i<n; i++) v.emplace_back(a[i], b[i]);
    sort(v.rbegin(), v.rend());
    int ans = 1e9;
    for(int i=0; i<(1<<n); i++){
        int cnt = 0, sum = 0;
        for(int j=0; j<n; j++) if((i>>j)&1) cnt+=v[j].second, sum+=v[j].first;
        if(cnt == 0) continue;
        int res = (sum*1000+cnt-1)/cnt;
        if(res >= ans) continue;
        vector<int> used(n, 0);
        for(int j=0; j<n; j++) if((i>>j)&1) used[j] = 1;
        int curr = sum, curr_cnt = cnt;
        for(int j=0; j<n; j++) if(!used[j]){
            for(int k=j+1; k<n; k++) if(!used[k] && v[k].first < v[j].first){
                curr += v[k].first;
                curr_cnt += v[k].second;
                used[k] = 1;
                int tmp = (curr*1000+curr_cnt-1)/curr_cnt;
                if(tmp < ans) ans = tmp;
                curr -= v[k].first;
                curr_cnt -= v[k].second;
                used[k] = 0;
            }
        }
        if(curr_cnt > 0) ans = min(ans, (curr*1000+curr_cnt-1)/curr_cnt);
    }
    cout << ans;
}