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
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;

    vector<int> t(n, -1);
    t[0] = 0;
    bool possible = true;

    for(int i = 0; i < n-1; i++){
        int necessary_or = a[i];
        int necessary_and = b[i];
        int next = -1;

        for(int k = 0; k <= 3; k++){
            if((t[i] | k) == necessary_or && (t[i] & k) == necessary_and){
                next = k;
                break;
            }
        }

        if(next == -1){
            possible = false;
            break;
        }

        t[i+1] = next;
    }

    if(possible){
        cout << "YES\n";
        for(auto x: t) cout << x << ' ';
        cout << '\n';
    }
    else{
        cout << "NO\n";
    }

    return 0;
}