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
    vector<long long> a(n);
    for(auto &x: a) cin >> x;
    
    bool asc = true, desc = true;
    for(int i=1; i<n; ++i){
        if(a[i] < a[i-1]) asc = false;
        if(a[i] > a[i-1]) desc = false;
    }
    if(!asc || !desc){
        cout << "-1";
        return 0;
    }
    
    for(int i=0; i<n-1; ++i){
        for(int j=i+1; j<n; ++j){
            if(a[i] != a[j]){
                swap(a[i], a[j]);
                bool new_asc = true, new_desc = true;
                for(int k=1; k<n; ++k){
                    if(a[k] < a[k-1]) new_asc = false;
                    if(a[k] > a[k-1]) new_desc = false;
                }
                if(!new_asc || !new_desc){
                    cout << i+1 << " " << j+1;
                    return 0;
                }
                swap(a[i], a[j]);
            }
        }
    }
    cout << "-1";
}