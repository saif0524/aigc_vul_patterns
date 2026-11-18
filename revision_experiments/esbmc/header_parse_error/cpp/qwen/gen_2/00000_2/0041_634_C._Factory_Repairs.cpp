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
    int n, k, a, b, q;
    cin >> n >> k >> a >> b >> q;
    vector<int> orders(n+1, 0);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int d, amount;
            cin >> d >> amount;
            orders[d] += amount;
        }
        else{
            int p;
            cin >> p;
            long long filled = 0;
            long long current = 0;
            for(int i=1;i<p;i++){
                current += b;
                filled += min(orders[i], (int)current);
                current -= min(orders[i], (int)current);
            }
            for(int i=p;i<=p+k-1;i++){
                filled += min(orders[i], 0);
            }
            for(int i=p+k;i<=n;i++){
                current += a;
                filled += min(orders[i], (int)current);
                current -= min(orders[i], (int)current);
            }
            cout << filled << "\n";
        }
    }
}