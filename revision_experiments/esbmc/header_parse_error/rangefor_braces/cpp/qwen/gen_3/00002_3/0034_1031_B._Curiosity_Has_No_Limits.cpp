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
    int n;
    cin >> n;
    vector<int> a(n-1), b(n-1);
    for(auto &x: a) { cin >> x; }
    for(auto &x: b) { cin >> x; }
    vector<int> t(n);
    t[0] = 2;
    bool found = false;
    for(int i=0;i<4 && !found;i++){
        t[0] = i;
        found = true;
        for(int j=1;j<n;j++){
            int lo = 0, hi = 4;
            for(int k=0;k<4;k++){
                if((t[j-1]|k) == a[j-1] && (t[j-1]&k) == b[j-1]){
                    lo = k, hi = k+1;
                    break;
                }
            }
            if(hi == 4){
                found = false;
                break;
            }
            t[j] = lo;
        }
    }
    if(found){
        cout << "YES\n";
        for(auto &x: t) { cout << x << ' '; }
    }
    else{
        cout << "NO";
    }
}