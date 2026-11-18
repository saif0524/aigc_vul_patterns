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
    vector<long long> a(n);
    for(auto &x: a) cin >> x;
    vector<long long> pref(n+1, 0);
    for(int i=0; i<n; i++){
        pref[i+1] = pref[i] + a[i];
    }
    map<long long, vector<int>> mp;
    for(int i=0; i<n; i++){
        mp[a[i]].push_back(i);
    }
    long long mx = LLONG_MIN;
    pair<int,int> p;
    for(auto &[val, indices]: mp){
        if(indices.size() < 2) continue;
        int first = indices.front(), last = indices.back();
        long long sum = pref[last+1] - pref[first];
        if(sum > mx){
            mx = sum;
            p = {first, last};
        }
    }
    int k = n - (p.second - p.first + 1);
    cout << mx << " " << k << "\n";
    for(int i=0; i<n; i++){
        if(i < p.first || i > p.second){
            cout << i+1 << " ";
        }
    }
    cout << "\n";
}