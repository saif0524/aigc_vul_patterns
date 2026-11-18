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
        vector<long long> a(n);
        for(auto &x: a) cin >> x;
        if(n == 1){
            cout << "Yes\n";
            continue;
        }
        vector<bool> left(n, false), right(n, false);
        left[0] = true;
        for(int i=1; i<n; i++){
            if(a[i] < a[i-1]){
                left[i] = left[i-1];
            }
            else if(a[i] == a[i-1]){
                left[i] = false;
            }
            else{
                left[i] = true;
            }
        }
        right[n-1] = true;
        for(int i=n-2; i>=0; i--){
            if(a[i] < a[i+1]){
                right[i] = right[i+1];
            }
            else if(a[i] == a[i+1]){
                right[i] = false;
            }
            else{
                right[i] = true;
            }
        }
        bool possible = false;
        for(int i=0; i<n; i++){
            if(left[i] && right[i]){
                possible = true;
                break;
            }
        }
        cout << (possible ? "Yes\n" : "No\n");
    }
}