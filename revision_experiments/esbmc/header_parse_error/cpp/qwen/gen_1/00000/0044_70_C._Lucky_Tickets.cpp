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

int rev(int x) {
    int ans = 0;
    while (x > 0) {
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int maxx, maxy, w;
    cin >> maxx >> maxy >> w;
    int cnt = 0;
    int ansx = -1, ansy = -1;
    for(int x = 1; x <= maxx; x++){
        for(int y = 1; y <= maxy; y++){
            if(1LL * x * y > 1e9) continue;
            if(x * y == rev(x) * rev(y)){
                cnt++;
            }
            if(cnt >= w){
                ansx = x;
                ansy = y;
                break;
            }
        }
        if(cnt >= w) break;
    }
    if(ansx == -1) cout << "-1\n";
    else cout << ansx << " " << ansy << "\n";
}