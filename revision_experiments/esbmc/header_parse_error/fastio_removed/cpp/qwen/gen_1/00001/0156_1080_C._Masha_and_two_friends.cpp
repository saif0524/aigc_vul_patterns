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

typedef long long ll;

int main(){
    ((void)0);
    ((void)0);
    int t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll x3, y3, x4, y4;
        cin >> x3 >> y3 >> x4 >> y4;
        ll white = 0, black = 0;
        ll total = n * m;
        ll w = (x2 - x1 + 1) * (y2 - y1 + 1);
        ll b = (x4 - x3 + 1) * (y4 - y3 + 1);
        ll overlap_x1 = max(x1, x3);
        ll overlap_y1 = max(y1, y3);
        ll overlap_x2 = min(x2, x4);
        ll overlap_y2 = min(y2, y4);
        ll overlap = 0;
        if(overlap_x1 <= overlap_x2 && overlap_y1 <= overlap_y2){
            overlap = (overlap_x2 - overlap_x1 + 1) * (overlap_y2 - overlap_y1 + 1);
        }
        white = w - overlap;
        black = b;
        white += overlap;
        total -= (white + black);
        white += total / 2;
        black += total - total / 2;
        if((n % 2 == 1 && m % 2 == 1) && (y1 + x1) % 2 == (y2 + x2) % 2 && (y3 + x3) % 2 == (y4 + x4) % 2 && (y1 + x1) % 2 != (y3 + x3) % 2){
            if(overlap % 2 == 1){
                white++;
                black--;
            }
        }
        cout << white << " " << black << "\n";
    }
}