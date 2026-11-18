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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = n-1;
        for(int i=0; i<n; i++){
            int l=0, r=0;
            int del = 0;
            for(int j=i; j<n; j++){
                if(s[j] == '>') r++;
                else l++;
                if(l > r){
                    del = j-i+1;
                    break;
                }
            }
            if(l == r) ans = min(ans, del);
        }
        for(int i=0; i<n; i++){
            int l=0, r=0;
            int del = 0;
            for(int j=i; j>=0; j--){
                if(s[j] == '>') r++;
                else l++;
                if(r < l){
                    del = i-j+1;
                    break;
                }
            }
            if(l == r) ans = min(ans, del);
        }
        cout << ans << endl;
    }
}