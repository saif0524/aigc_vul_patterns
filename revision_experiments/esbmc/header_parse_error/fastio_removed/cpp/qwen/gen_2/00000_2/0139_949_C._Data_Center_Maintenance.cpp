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
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> u(n);
    for(auto &x: u) cin >> x;
    vector<vector<int>> cl(n+1);
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        cl[x].push_back(y);
        cl[y].push_back(x);
    }
    vector<int> ans;
    for(int i=1; i<=n; i++){
        bool ok = true;
        for(auto &j: cl[i]){
            if(u[i] == u[j]){
                ok = false;
                break;
            }
        }
        if(ok) continue;
        ans.push_back(i);
        u[i] = (u[i] + 1) % h;
        for(auto &j: cl[i]){
            if(u[i] == u[j]){
                ok = false;
                break;
            }
        }
        if(ok) break;
    }
    cout << ans.size() << "\n";
    for(auto &x: ans) cout << x << " ";
    cout << "\n";
}