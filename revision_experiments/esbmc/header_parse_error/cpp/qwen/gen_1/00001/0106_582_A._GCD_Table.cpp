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
    vector<int> gcd_table(n*n);
    for(int &x: gcd_table) cin >> x;
    sort(gcd_table.begin(), gcd_table.end(), greater<int>());
    vector<int> a(n);
    set<int> used;
    int idx = 0;
    for(int i=0; i<n; ++i){
        while(used.count(gcd_table[idx])) idx++;
        a[i] = gcd_table[idx];
        used.insert(a[i]);
        for(int j=0; j<i; ++j){
            int g = __gcd(a[i], a[j]);
            used.insert(g);
        }
    }
    for(int i=0; i<n; ++i){
        if(i) cout << " ";
        cout << a[i];
    }
    cout << "\n";
}