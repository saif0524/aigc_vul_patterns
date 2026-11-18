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
const int MOD = 1e9 + 7;
const int MAX = 5e5 + 10;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> basis;
    vector<bool> added(m+1, false);
    for(int i = 1; i <= n; ++i){
        int k;
        cin >> k;
        if(k == 1){
            int x;
            cin >> x;
            if(!added[x]){
                basis.push_back(x);
                added[x] = true;
            }
        }
        else if(k == 2){
            int x, y;
            cin >> x >> y;
            if(x > y) swap(x, y);
            if(!added[x] && !added[y]){
                basis.push_back(x);
                basis.push_back(y);
                added[x] = added[y] = true;
            }
            else if(added[x] && !added[y]){
                basis.push_back(y);
                added[y] = true;
            }
            else if(!added[x] && added[y]){
                basis.push_back(x);
                added[x] = true;
            }
        }
    }
    ll sz = (1LL << basis.size());
    cout << sz % MOD << " " << basis.size() << "\n";
    for(auto &x : basis){
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}