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
    vector<int> gcds(n*n);
    for(auto &x: gcds) cin >> x;
    sort(gcds.begin(), gcds.end(), greater<int>());
    vector<int> a;
    for(int i=0; i<n; ++i){
        bool found = false;
        for(int j=0; j<n*n; ++j){
            if(gcds[j]!=0){
                int g = gcds[j];
                bool valid = true;
                for(int k=0; k<a.size(); ++k){
                    if(gcd(g, a[k]) != gcds[i*n+k]){
                        valid = false;
                        break;
                    }
                }
                if(valid){
                    a.push_back(g);
                    gcds[j] = 0;
                    found = true;
                    break;
                }
            }
        }
        if(!found) return -1;
    }
    for(int i=0; i<n; ++i){
        cout << a[i] << (i<n-1?' ':'\n');
    }
}