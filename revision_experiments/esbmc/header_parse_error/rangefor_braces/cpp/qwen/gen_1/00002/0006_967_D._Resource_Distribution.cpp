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

int main() {
    ((void)0);
    ((void)0);
    
    int n;
    long long x1, x2;
    cin >> n >> x1 >> x2;
    
    vector<long long> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];
    
    sort(c.rbegin(), c.rend());
    
    for(int k1 = 1; k1 <= n; k1++) {
        long long req1 = x1 / k1;
        long long sum1 = 0;
        vector<int> use1;
        int pos = 0;
        
        while(use1.size() < k1) {
            if(c[pos] >= req1) {
                use1.push_back(pos+1);
                sum1 += c[pos];
                pos++;
            } else {
                break;
            }
        }
        
        if(use1.size() < k1) continue;
        
        long long remaining = x1 % k1;
        if(remaining > 0) {
            if(c[pos] >= remaining) {
                use1.push_back(pos+1);
                pos++;
            } else {
                continue;
            }
        }
        
        req1 = x2 / (n-k1);
        long long sum2 = 0;
        vector<int> use2;
        
        while(use2.size() < n-k1) {
            if(c[pos] >= req1) {
                use2.push_back(pos+1);
                sum2 += c[pos];
                pos++;
            } else {
                break;
            }
        }
        
        if(use2.size() < n-k1) continue;
        
        remaining = x2 % (n-k1);
        if(remaining > 0) {
            if(c[pos] >= remaining) {
                use2.push_back(pos+1);
            } else {
                continue;
            }
        }
        
        cout << "Yes\n";
        cout << k1 << " " << n-k1 << "\n";
        for(int i : use1) { cout << i << " "; }
        cout << "\n";
        for(int i : use2) { cout << i << " "; }
        cout << "\n";
        return 0;
    }
    
    cout << "No\n";
}