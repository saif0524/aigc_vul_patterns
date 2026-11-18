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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int, long long>> vec(n);
        for(auto &p: vec){
            cin >> p.first >> p.second;
        }
        sort(vec.begin(), vec.end());
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long ans = 0, current = 0;
        for(int i=0;i<n;i++){
            if(current < vec[i].first){
                while(!pq.empty() && current < vec[i].first){
                    current++;
                    ans += pq.top();
                    pq.pop();
                }
            }
            if(current < vec[i].first){
                ans += vec[i].second;
                current++;
            }
            else{
                pq.push(vec[i].second);
            }
        }
        cout << ans << "\n";
    }
}