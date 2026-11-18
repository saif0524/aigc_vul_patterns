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
    long long a, b;
    cin >> a >> b;
    if(a > b) swap(a, b);
    queue<pair<long long, int>> q;
    q.push({a, 0});
    set<long long> visited;
    visited.insert(a);
    while(!q.empty()){
        auto [current, steps] = q.front();
        q.pop();
        if(current == b){
            cout << steps;
            return 0;
        }
        if(current * 2 <= 1e9 && !visited.count(current * 2)){
            q.push({current * 2, steps + 1});
            visited.insert(current * 2);
        }
        if(current * 3 <= 1e9 && !visited.count(current * 3)){
            q.push({current * 3, steps + 1});
            visited.insert(current * 3);
        }
        if(current * 5 <= 1e9 && !visited.count(current * 5)){
            q.push({current * 5, steps + 1});
            visited.insert(current * 5);
        }
        if(current % 2 == 0 && !visited.count(current / 2)){
            q.push({current / 2, steps + 1});
            visited.insert(current / 2);
        }
        if(current % 3 == 0 && !visited.count(current * 3 / 2)){
            q.push({current * 3 / 2, steps + 1});
            visited.insert(current * 3 / 2);
        }
        if(current % 5 == 0 && !visited.count(current * 5 / 4)){
            q.push({current * 5 / 4, steps + 1});
            visited.insert(current * 5 / 4);
        }
    }
    cout << -1;
}