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
    int n, k;
    cin >> n >> k;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(k < n-1){
        cout << -1;
        return 0;
    }
    if(n == 4 && k == 3){
        cout << -1;
        return 0;
    }
    vector<int> path1, path2;
    path1.push_back(a);
    for(int i = 1; i <= n; ++i){
        if(i != a && i != b && i != c && i != d){
            path1.push_back(i);
        }
    }
    path1.push_back(b);
    path2.push_back(c);
    for(int i = 1; i <= n; ++i){
        if(i != a && i != b && i != c && i != d){
            path2.push_back(i);
        }
    }
    path2.push_back(d);
    if(path1.size() != n || path2.size() != n){
        cout << -1;
        return 0;
    }
    for(int i = 0; i < path1.size(); ++i){
        cout << path1[i] << (i == path1.size()-1 ? '\n' : ' ');
    }
    for(int i = 0; i < path2.size(); ++i){
        cout << path2[i] << (i == path2.size()-1 ? '\n' : ' ');
    }
}