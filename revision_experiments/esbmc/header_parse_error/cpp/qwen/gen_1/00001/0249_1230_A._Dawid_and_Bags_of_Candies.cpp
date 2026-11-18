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
    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    int total = a1 + a2 + a3 + a4;
    if(total % 2 != 0){
        cout << "NO\n";
        return 0;
    }
    int target = total / 2;
    bool possible = false;
    for(int i=0;i<(1<<4);i++){
        int sum = 0;
        if(i & (1<<0)) sum += a1;
        if(i & (1<<1)) sum += a2;
        if(i & (1<<2)) sum += a3;
        if(i & (1<<3)) sum += a4;
        if(sum == target){
            possible = true;
            break;
        }
    }
    if(possible) cout << "YES\n";
    else cout << "NO\n";
}