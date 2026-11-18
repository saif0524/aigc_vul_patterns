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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    map<pair<long long, long long>, int> ants;
    ants[{0, 0}] = n;
    bool changed = true;
    while(changed){
        changed = false;
        map<pair<long long, long long>, int> new_ants = ants;
        for(auto it : ants){
            long long x = it.first.first, y = it.first.second;
            int cnt = it.second;
            if(cnt >= 4){
                new_ants[{x, y}] -= cnt / 4 * 4;
                new_ants[{x + 1, y}] += cnt / 4;
                new_ants[{x - 1, y}] += cnt / 4;
                new_ants[{x, y + 1}] += cnt / 4;
                new_ants[{x, y - 1}] += cnt / 4;
                changed = true;
            }
        }
        ants = new_ants;
    }
    for(int i=0; i<t; i++){
        long long xi, yi;
        cin >> xi >> yi;
        cout << ants[{xi, yi}] << "\n";
    }
}