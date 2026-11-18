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
    long long X, K;
    cin >> X >> K;
    vector<long long> r(K);
    for(auto &x: r) cin >> x;
    long long Q;
    cin >> Q;
    vector<pair<long long, long long>> queries(Q);
    for(auto &[t, a]: queries) cin >> t >> a;

    vector<long long> transitions;
    transitions.push_back(0LL);
    for(auto &x: r) transitions.push_back(x);
    transitions.push_back((long long)1e18);

    vector<long long> top_sand(X+1, 0);
    for(long long a=0; a<=X; a++){
        long long current_sand = a;
        for(int i=0; i<transitions.size()-1; i++){
            long long start = transitions[i];
            long long end = transitions[i+1];
            long long duration = end - start;
            if(current_sand >= duration){
                top_sand[a] += duration;
                current_sand -= duration;
            }
            else{
                top_sand[a] += current_sand;
                break;
            }
            current_sand = X - current_sand;
        }
    }

    for(auto [t, a]: queries){
        long long total_sand = top_sand[a];
        long long net_sand = 0;
        for(int i=0; i<transitions.size()-1; i++){
            long long start = transitions[i];
            long long end = transitions[i+1];
            if(t < start) break;
            long long duration = end - start;
            if(net_sand == a){
                net_sand -= min(duration, t - start);
            }
            else{
                net_sand += min(duration, t - start);
            }
            if(net_sand > a){
                net_sand = a - (net_sand - a);
            }
            else if(net_sand < 0){
                net_sand = 0;
            }
        }
        cout << a - min(a, net_sand) << "\n";
    }
}