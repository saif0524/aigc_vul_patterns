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
    ((void)0);
    ((void)0);
    
    int n, k, a, b, q;
    cin >> n >> k >> a >> b >> q;
    
    vector<long long> orders(n + 1, 0);
    vector<long long> prefix(n + 1, 0);
    
    for(int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if(type == 1) {
            int d, a;
            cin >> d >> a;
            orders[d] += a;
        } else {
            int p;
            cin >> p;
            if(p > 1) {
                prefix[p] += prefix[p - 1];
            }
            long long available = 0;
            for(int i = 1; i <= n; i++) {
                prefix[i] += orders[i];
                if(i < p || i >= p + k) {
                    available += min((long long)a, prefix[i]);
                } else {
                    available += min((long long)b, prefix[i]);
                }
            }
            cout << available << '\n';
            prefix.assign(n + 1, 0);
        }
    }
    return 0;
}