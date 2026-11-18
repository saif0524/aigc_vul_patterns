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
    vector<long long> a(n);
    for(auto &x: a) cin >> x;
    map<long long, vector<int>> m;
    for(int i=0;i<n;i++) m[a[i]].push_back(i);
    long long sum=LLONG_MIN;
    pair<int,int> range={-1,-1};
    for(const auto &[val, idxs]: m){
        if(idxs.size()>=2){
            for(int i=0,j=idxs.size()-1;i<j;i++,j--){
                long long current_sum = accumulate(a.begin()+idxs[i], a.begin()+idxs[j]+1, 0LL);
                if(current_sum > sum){
                    sum = current_sum;
                    range = {idxs[i], idxs[j]};
                }
                break; // Only need the first and last to satisfy the condition
            }
        }
    }
    cout << sum << " " << (n-(range.second-range.first+1)) << "\n";
    for(int i=0;i<n;i++){
        if(i<range.first || i>range.second){
            cout << i+1 << " ";
        }
    }
    cout << "\n";
}