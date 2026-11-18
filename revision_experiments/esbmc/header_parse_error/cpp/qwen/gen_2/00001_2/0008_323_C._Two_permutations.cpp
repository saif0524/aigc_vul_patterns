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
    vector<int> p(n+1), q(n+1), pos_p(n+1), pos_q(n+1);
    for(int i=1;i<=n;i++) cin >> p[i];
    for(int i=1;i<=n;i++) cin >> q[i];
    for(int i=1;i<=n;i++) pos_p[p[i]] = i;
    for(int i=1;i<=n;i++) pos_q[q[i]] = i;
    int m;
    cin >> m;
    int x = 0;
    auto f = [&](int z){ return ((z - 1 + x) % n) + 1; };
    while(m--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int l1 = min(f(a), f(b)), r1 = max(f(a), f(b));
        int l2 = min(f(c), f(d)), r2 = max(f(c), f(d));
        int count = 0;
        for(int i=1;i<=n;i++){
            if(pos_p[i] >= l1 && pos_p[i] <= r1 && pos_q[i] >= l2 && pos_q[i] <= r2){
                count++;
            }
        }
        cout << count << "\n";
        x = count + 1;
    }
}