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
    int n;
    cin >> n;
    while(n--){
        long long a, b;
        cin >> a >> b;
        bool possible = false;
        for(long long k = 1; k*k <= a && !possible; k++){
            if(a % (k*k) == 0){
                long long aa = a / (k*k);
                if(b % k == 0 && b / k == aa){
                    possible = true;
                }
            }
        }
        for(long long k = 1; k*k <= b && !possible; k++){
            if(b % (k*k) == 0){
                long long bb = b / (k*k);
                if(a % k == 0 && a / k == bb){
                    possible = true;
                }
            }
        }
        if(possible) cout << "Yes\n";
        else cout << "No\n";
    }
}