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
    int n, m;
    cin >> n >> m;
    vector<int> highest(n+1, 0);
    for(int i=0;i<m;i++){
        int l, r;
        cin >> l >> r;
        highest[l]=r;
    }

    for(int i=1;i<=n;i++){
        highest[i]=max(highest[i], highest[i-1]);
    }

    int q;
    cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;
        int ans=x;
        for(int i=x;i<=y;i++){
            ans=max(ans, highest[i]);
            if(ans==y) break;
        }
        cout << ans << "\n";
    }
}