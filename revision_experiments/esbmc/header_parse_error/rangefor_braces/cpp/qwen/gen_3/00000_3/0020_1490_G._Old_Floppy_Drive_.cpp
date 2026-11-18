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
        int n, m;
        cin >> n >> m;
        vector<long long> a(n);
        for(auto &x: a) { cin >> x; }
        vector<long long> x(m);
        for(auto &x: x) { cin >> x; }
        long long su = accumulate(a.begin(), a.end(), (long long)0);
        vector<long long> pre(n+1);
        for(int i=1;i<=n;i++) pre[i] = pre[i-1] + a[i-1];
        vector<int> ans(m);
        for(int i=0;i<m;i++){
            if(x[i] == 0){
                ans[i] = 0;
                continue;
            }
            if(su > 0){
                long long need = x[i] - 1 - (pre[n] - 1)%su;
                need = (need + su - 1)/su;
                ans[i] = need * n;
                x[i] -= need * su;
            }
            if(x[i] <= 0){
                continue;
            }
            int l = 0, r = n-1;
            while(l < r){
                int mid = (l + r) / 2;
                if(pre[mid+1] >= x[i]){
                    r=mid;
                }else{
                    l=mid+1;
                }
            }
            if(pre[l+1] < x[i]) ++l;
            ans[i] += l+1;
        }
        for(auto &x: ans){
            if(x == 0) cout << "0 ";
            else if(x > 2e9) cout << "-1 ";
            else cout << x << " ";
        }
        cout << "\n";
    }
}