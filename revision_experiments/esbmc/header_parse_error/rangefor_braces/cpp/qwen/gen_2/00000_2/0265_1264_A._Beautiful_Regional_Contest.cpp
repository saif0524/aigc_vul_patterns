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
        vector<int> p(n);
        for(auto &x: p) { cin >> x; }
        int g = 0, s = 0, b = 0;
        for(int i=0; i<n; ++i){
            if(g==0 && (i+1)*2<=n){
                g = 1;
                continue;
            }
            if(g>0 && s<g && (i+1)*2<=n && p[i]<p[i-g]){
                s = g;
                continue;
            }
            if(s>0 && b<g && (i+1)*2<=n && p[i]<p[i-s]){
                b = g;
                continue;
            }
            if(g>0 && s>0 && b>0 && (i+1)*2<=n && p[i]<p[i-b]){
                b++;
                if(b>=s){
                    g++;
                    s = b;
                    b = g;
                }
            }
        }
        if(g==0 || s==0 || b==0 || g>=s || g>=b){
            cout << 0 << ' ' << 0 << ' ' << 0 << '\n';
        }
        else{
            cout << g << ' ' << s << ' ' << b << '\n';
        }
    }
}