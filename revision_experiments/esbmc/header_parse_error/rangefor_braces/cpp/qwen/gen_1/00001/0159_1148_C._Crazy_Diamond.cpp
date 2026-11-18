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
    ((void)0);
    ((void)0);
    int n;
    cin >> n;
    vector<int> p(n);
    for(auto &x : p) { cin >> x; }
    vector<int> pos(n+1);
    for(int i=0;i<n;i++) pos[p[i]] = i;
    int swaps = 0;
    vector<pair<int, int>> result;
    for(int i=0;i<n/2;i++){
        if(p[i] != i+1){
            int target = pos[i+1];
            if(abs(i - target) < n/2){
                if(target < n/2){
                    result.push_back({i+1, n/2 +1});
                    target = n/2 + 1;
                }else{
                    result.push_back({i+1, n/2});
                    target = n/2;
                }
                swaps++;
            }
            result.push_back({i+1, target+1});
            pos[p[i]] = target;
            pos[i+1] = i;
            swap(p[i], p[target]);
            swaps++;
        }
    }
    cout << swaps << "\n";
    for(auto &x : result) { cout << x.first << " " << x.second << "\n"; }
}