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
    vector<string> p(n);
    for(auto &s: p) cin >> s;
    pair<char,long long> best = {' ',0};
    pair<char,long long> last = {' ',0};
    for(auto &s: p){
        if(s.size()==1){
            if(last.first == s[0]){
                last.second++;
            }else{
                best = max(best, last);
                last = {s[0], 1};
            }
        }else{
            best = max(best, last);
            best = max(best, pair<char, long long>{s[0], 1});
            best = max(best, pair<char, long long>{s.back(), 1});
            if(last.first == s[0]){
                last.second += 1;
            }else{
                last = {s[0], 1};
            }
            if(s.back() == s.front()){
                last.second += s.size()-1;
            }else{
                best = max(best, pair<char, long long>{s.back(), (long long)s.size()-1});
            }
        }
    }
    best = max(best, last);
    cout << best.second;
}