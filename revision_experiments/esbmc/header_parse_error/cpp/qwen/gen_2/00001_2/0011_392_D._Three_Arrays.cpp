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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    for(auto &x : c) cin >> x;
    unordered_map<int, int> need;
    for(int i=0;i<n;i++){
        need[a[i]]++;
        need[b[i]]++;
        need[c[i]]++;
    }
    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++) arr.push_back({a[i],0});
    for(int i=0;i<n;i++) arr.push_back({b[i],1});
    for(int i=0;i<n;i++) arr.push_back({c[i],2});
    sort(arr.begin(), arr.end());
    vector<int> have(3,0);
    int ans = need.size();
    int l = 0, r = 0;
    while(r < 3*n){
        while(r < 3*n && have[arr[r].second] != need[arr[r].first]){
            have[arr[r].second]++;
            r++;
        }
        if(r == 3*n) break;
        ans = min(ans, r - l);
        while(l < r && have[arr[l].second] > need[arr[l].first]){
            have[arr[l].second]--;
            l++;
        }
        ans = min(ans, r - l);
        if(r != 3*n - 1 && arr[r].first != arr[r+1].first){
            have[arr[l].second]--;
            l++;
        }
    }
    cout << ans;
    return 0;
}