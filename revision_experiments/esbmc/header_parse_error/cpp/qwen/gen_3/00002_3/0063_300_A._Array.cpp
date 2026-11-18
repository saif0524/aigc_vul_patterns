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
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    int z = 0, p = 0, np = 0;
    vector<int> zero, pos, neg;
    for(auto x: a){
        if(x == 0) z++, zero.push_back(x);
        else if(x > 0) p++, pos.push_back(x);
        else np++, neg.push_back(x);
    }
    if(z == 0){
        z = 1;
        if(p >= 2 && np >= 1){
            zero.push_back(pos.back());
            pos.pop_back();
        }
        else if(p >= 3){
            zero.push_back(pos.back());
            pos.pop_back();
        }
        else{
            zero.push_back(neg.back());
            neg.pop_back();
        }
    }
    if(pos.empty()){
        pos.push_back(neg.back());
        neg.pop_back();
        pos.push_back(neg.back());
        neg.pop_back();
    }
    if(neg.empty()){
        neg.push_back(pos.back());
        pos.pop_back();
        neg.push_back(pos.back());
        pos.pop_back();
    }
    if(p == 0 && np >= 3){
        pos.push_back(neg.back());
        neg.pop_back();
    }
    if(p == 1 && np >= 2){
        pos.push_back(neg.back());
        neg.pop_back();
    }
    cout << 1 << " " << neg.back() << "\n";
    neg.pop_back();
    cout << neg.size() + pos.size() << " ";
    for(auto x: neg) cout << x << " ";
    for(auto x: pos) cout << x << " ";
    cout << "\n";
    cout << z << " ";
    for(auto x: zero) cout << x << " ";
    cout << "\n";
}