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
        bool inc = true, dec = true;
        for(int i=1;i<n;i++){
            if(a[i] <= a[i-1]) inc = false;
        }
        if(inc){
            cout << "Yes\n";
            continue;
        }
        for(int i=1;i<n;i++){
            if(a[i] <= a[i-1]) dec = false;
        }
        if(dec){
            cout << "Yes\n";
            continue;
        }
        bool possible = false;
        for(int i=0;i<n;i++){
            if((i+1 < n && a[i] > a[i+1]) && (i-1 >= 0 && a[i-1] < a[i])){
                possible = true;
                break;
            }
        }
        if(possible){
            cout << "Yes\n";
        }
        else{
            for(int i=0;i<n;i++){
                if(i+1 < n && a[i] < a[i+1]){
                    possible = true;
                    break;
                }
            }
            if(possible){
                for(int i=0;i<n;i++){
                    if(i-1 >= 0 && a[i] < a[i-1]){
                        possible = true;
                        break;
                    }
                }
            }
            if(possible){
                cout << "Yes\n";
            }
            else{
                cout << "No\n";
            }
        }
    }
}