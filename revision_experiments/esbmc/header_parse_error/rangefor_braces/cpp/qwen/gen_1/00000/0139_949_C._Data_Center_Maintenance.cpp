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
    for(auto &x: u) { cin >> x; }
    vector<set<int>> cl(h);
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        --a, --b;
        cl[u[a]].insert(min(a, b));
        cl[u[b]].insert(max(a, b));
    }
    vector<int> ans;
    for(int i = 0; i < h; ++i){
        set<int> toAdd;
        for(auto x: cl[i]){
            if(cl[(i+1)%h].count(x)){
                toAdd.insert(x);
            }
        }
        for(auto x: toAdd){
            cl[i].erase(x);
            cl[(i+1)%h].erase(x);
            ans.push_back(x+1);
        }
        if(ans.size() == n) break;
    }
    cout << ans.size() << "\n";
    for(auto x: ans) { cout << x << " "; }
    cout << "\n";
}