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
    int t;
    cin >> t;
    while(t--){
        long long n, m;
        cin >> n >> m;
        vector<pair<long long, long long>> apps(n);
        long long total = 0;
        for(long long i=0;i<n;i++){
            cin >> apps[i].first;
        }
        for(long long i=0;i<n;i++){
            cin >> apps[i].second;
            total += apps[i].second;
        }
        sort(apps.begin(), apps.end());
        vector<long long> suffix(n+1, 0);
        for(long long i=n-1;i>=0;i--){
            suffix[i] = suffix[i+1] + apps[i].first;
        }
        long long ans = LLONG_MAX;
        long long current = 0;
        long long j = 0;
        for(long long i=0;i<n;i++){
            while(j <= n && current < m){
                current += apps[j].first;
                j++;
            }
            if(j <= n && current >= m){
                ans = min(ans, total - (suffix[i] + current - apps[j-1].first));
            }
            if(j == n && current >= m){
                ans = min(ans, total - (suffix[i]));
            }
            total -= apps[i].second;
            current -= apps[i].first;
        }
        if(ans == LLONG_MAX){
            cout << "-1\n";
        }
        else{
            cout << ans << "\n";
        }
    }
}