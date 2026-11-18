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
    int n, m, k;
    cin >> n >> m >> k;
    vector<set<int>> friends(n);
    vector<int> ans(m, 0);
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        friends[x].insert(y);
        friends[y].insert(x);
        for(auto &p : {x, y}){
            int cnt = 0;
            for(auto &f : friends[p]){
                if(friends[f].size() >= k){
                    cnt++;
                }
            }
            if(cnt >= k){
                ans[i] = max(ans[i], cnt + 1);
            }
        }
    }
    for(int i=0; i<m; i++){
        if(i > 0){
            ans[i] = max(ans[i], ans[i-1]);
        }
        cout << ans[i] << "\n";
    }
}