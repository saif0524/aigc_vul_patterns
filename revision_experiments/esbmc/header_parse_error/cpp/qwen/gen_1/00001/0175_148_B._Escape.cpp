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

int main() {
    int vp, vd, t, f, c;
    cin >> vp >> vd >> t >> f >> c;
    
    int princess_distance = vp * t;
    int dragon_distance = 0;
    int bijous = 0;
    
    while (princess_distance < c) {
        int time_to_catch = (princess_distance * (vd - vp)) / (vd * vp);
        int new_dragon_distance = dragon_distance + time_to_catch * vd;
        
        if (new_dragon_distance >= princess_distance) {
            bijous++;
            dragon_distance = 0;
            princess_distance += vp * (t + f);
        } else {
            princess_distance += vp * time_to_catch;
            dragon_distance = new_dragon_distance;
        }
    }
    
    cout << bijous;
}