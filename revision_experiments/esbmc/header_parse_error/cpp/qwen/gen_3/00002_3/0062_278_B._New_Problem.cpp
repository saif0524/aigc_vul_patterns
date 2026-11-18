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
    int n;
    cin >> n;
    vector<string> titles(n);
    for(auto &s: titles) cin >> s;
    
    string res;
    for(int len=1;len<=20;len++){
        for(int i=0;i<(1<<len);i++){
            string candidate;
            for(int j=0;j<len;j++){
                if(i&(1<<j)) candidate += 'a'+j;
            }
            if(candidate.empty()) continue;
            bool found = false;
            for(auto &title: titles){
                if(title.find(candidate) != string::npos){
                    found = true;
                    break;
                }
            }
            if(!found){
                if(res.empty() || candidate < res){
                    res = candidate;
                }
            }
        }
        if(!res.empty()) break;
    }
    cout << res;
}