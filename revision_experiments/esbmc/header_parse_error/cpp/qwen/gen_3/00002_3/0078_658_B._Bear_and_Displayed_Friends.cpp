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
    int n, k, q;
    cin >> n >> k >> q;
    vector<long long> t(n);
    for(auto &x: t) cin >> x;
    set<pair<long long, int>> online;
    vector<bool> isOnline(n+1, false);
    for(int i=0;i<q;++i){
        int type, id;
        cin >> type >> id;
        if(type==1){
            if(online.size() < k){
                online.insert({t[id-1], id});
                isOnline[id] = true;
            }else{
                auto it = online.begin();
                if(t[id-1] > (*it).first){
                    isOnline[(*it).second] = false;
                    isOnline[id] = true;
                    online.erase(it);
                    online.insert({t[id-1], id});
                }
            }
        }else{
            if(isOnline[id]) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}