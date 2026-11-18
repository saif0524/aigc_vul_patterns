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
    int n;
    cin >> n;
    set<int> factors;
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        int g = __gcd(a, b);
        for(int j=2;j*j<=g;j++){
            if(g % j == 0){
                factors.insert(j);
                while(g % j == 0){
                    g /= j;
                }
            }
        }
        if(g > 1){
            factors.insert(g);
        }
    }
    set<int> common_factors;
    bool first = true;
    for(auto f : factors){
        bool is_common = true;
        for(int i=0;i<n;i++){
            int a, b;
            cin >> a >> b;
            if(a % f != 0 && b % f != 0){
                is_common = false;
                break;
            }
        }
        if(is_common){
            common_factors.insert(f);
        }
        if(first){
            cin.clear();
            cin.seekg(0, ios::beg);
            first = false;
        }
    }
    if(common_factors.empty()){
        cout << -1;
    } else {
        cout << *common_factors.begin();
    }
}