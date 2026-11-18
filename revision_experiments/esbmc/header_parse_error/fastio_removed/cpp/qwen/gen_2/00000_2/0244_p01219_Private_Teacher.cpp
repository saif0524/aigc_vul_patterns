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
    ((void)0);((void)0);
    while(1){
        long long n, w; cin >> n >> w;
        if(n == 0 && w == 0) break;
        long long totalLessons = 0;
        for(int i=0;i<n;i++){
            long long ti, ci; cin >> ti >> ci;
            totalLessons += ti;
            set<string> days;
            string day;
            for(int j=0;j<ci;j++){
                cin >> day;
                days.insert(day);
            }
        }
        long long availableDays = w * 7;
        if(totalLessons <= availableDays) cout << "Yes\n";
        else cout << "No\n";
    }
}