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
    int a, b, h, w, n;
    cin >> a >> b >> h >> w >> n;
    vector<int> ext(n);
    for(auto &x: ext) { cin >> x; }
    if((h >= a && w >= b) || (h >= b && w >= a)){
        cout << 0;
        return 0;
    }
    sort(ext.begin(), ext.end(), greater<int>());
    int ans = -1;
    for(int i = 0; i < (1 << n); ++i){
        int nh = h, nw = w;
        int used = 0;
        for(int j = 0; j < n; ++j){
            if(i & (1 << j)){
                if(nh < a && nh * ext[j] < a) nh *= ext[j];
                else if(nw < b && nw * ext[j] < b) nw *= ext[j];
                else if(nh < b && nh * ext[j] < b) nh *= ext[j];
                else if(nw < a && nw * ext[j] < a) nw *= ext[j];
                else continue;
                used++;
            }
        }
        if((nh >= a && nw >= b) || (nh >= b && nw >= a)){
            if(ans == -1 || used < ans) ans = used;
        }
    }
    cout << ans;
}