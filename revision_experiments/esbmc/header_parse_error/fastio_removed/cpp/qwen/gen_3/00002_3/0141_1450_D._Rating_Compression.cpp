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
        int n;
        cin >> n;
        vector<int> a(n);
        for(int &x : a) cin >> x;
        vector<string> ans(n+1, "0");
        for(int k=1;k<=n;k++){
            deque<int> dq;
            vector<int> compress;
            for(int i=0;i<n;i++){
                while(!dq.empty() && dq.front()<i-k+1) dq.pop_front();
                while(!dq.empty() && a[dq.back()]>=a[i]) dq.pop_back();
                dq.push_back(i);
                if(i>=k-1) compress.push_back(a[dq.front()]);
            }
            bool is_permutation = true;
            vector<bool> seen(n+1, false);
            for(int x : compress){
                if(seen[x]){
                    is_permutation = false;
                    break;
                }
                seen[x] = true;
            }
            if(is_permutation) ans[k][0] = '1';
        }
        for(int k=1;k<=n;k++) cout << ans[k];
        cout << "\n";
    }
}