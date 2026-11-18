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
    vector<string> cities(m);
    for(auto &city: cities) cin >> city;
    int k;
    cin >> k;
    vector<string> a(k);
    vector<int> c(k);
    for(int i=0;i<k;i++) cin >> a[i] >> c[i];
    int x;
    cin >> x;
    vector<string> b(x);
    vector<int> d(x);
    for(int i=0;i<x;i++) cin >> b[i] >> d[i];
    int min_cost = INT_MAX, idx = -1;
    for(int i=0;i<k;i++){
        int cost = c[i];
        for(int j=0;j<x;j++){
            bool found = false;
            for(int l=0;l<m;l++){
                if(a[i] == cities[l] && b[j] == cities[l]){
                    cost += d[j];
                    found = true;
                    break;
                }
            }
            if(!found) break;
        }
        if(cost < min_cost){
            min_cost = cost;
            idx = i + 1;
        }
    }
    cout << min_cost << " " << idx;
}