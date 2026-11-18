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
    int a, b;
    long long n;
    cin >> a >> b >> n;
    
    long long ways = 1;
    for(int i=0; i<b; ++i){
        ways *= a;
        if(ways >= n){
            cout << "Masha" << endl;
            return 0;
        }
    }
    
    auto can_lose = [&](int na, int nb){
        long long nw = 1;
        for(int i=0; i<nb; ++i){
            nw *= na;
            if(nw >= n){
                return true;
            }
        }
        return false;
    };
    
    bool stas_lose_if_add_box = can_lose(a+1, b);
    bool stas_lose_if_add_item = can_lose(a, b+1);
    
    if(stas_lose_if_add_box && stas_lose_if_add_item){
        cout << "Missing" << endl;
    } else if(stas_lose_if_add_box){
        cout << "Masha" << endl;
    } else if(stas_lose_if_add_item){
        cout << "Stas" << endl;
    } else {
        cout << "Missing" << endl;
    }
    
    return 0;
}