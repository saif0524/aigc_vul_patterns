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

const int MOD = 1000000007;

int main(){
    ((void)0);
    ((void)0);
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i];
    }
    if(n==1){
        cout << a[0] % MOD;
        return 0;
    }
    set<long long> s;
    s.insert(a[0]);
    for(int i=1;i<n;i++){
        set<long long> ns;
        long long current = a[i];
        while(current <= *s.begin()){
            ns.insert(current);
            current *= b[i];
        }
        set_intersection(s.begin(), s.end(), ns.begin(), ns.end(), inserter(s, s.begin()));
        if(s.empty()){
            cout << -1;
            return 0;
        }
    }
    cout << *s.begin() % MOD;
}