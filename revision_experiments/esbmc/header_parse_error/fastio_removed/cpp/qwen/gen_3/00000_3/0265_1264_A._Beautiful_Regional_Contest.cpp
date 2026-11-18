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
        for(int &x: p) cin >> x;
        int g=0, s=0, b=0;
        for(int i=0;i<n-2 && (g+s+b)<=n/2;){
            if(p[i]>p[i+1] && p[i+1]>p[i+2]){
                g = 1;
                s = 1;
                b = 1;
                int j = i+3;
                while(j<n && p[j-1]>p[j] && (g+s+b)<=n/2){
                    if(b==s){
                        b++;
                    }else{
                        s++;
                    }
                    j++;
                }
                break;
            }
            i++;
        }
        if((g+s+b) > n/2){
            g=0,s=0,b=0;
        }
        cout << g << " " << s << " " << b << "\n";
    }
}