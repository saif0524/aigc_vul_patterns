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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for(int &x : a) { cin >> x; }
    for(int &x : b) { cin >> x; }
    
    int minInk = INT_MAX;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            int ink = 0;
            for(int k=0; k<m/2; ++k){
                ink += (a[i%a.size()] % n) + (b[j%b.size()] % n);
                i = (i+1)%n;
                j = (j-1+n)%n;
            }
            minInk = min(minInk, ink);
        }
    }
    
    cout << minInk * (m/2);
    return 0;
}