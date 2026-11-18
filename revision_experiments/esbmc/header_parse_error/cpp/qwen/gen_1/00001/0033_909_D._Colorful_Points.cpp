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
    string s;
    cin >> s;
    int n = s.size();
    int operations = 0;
    while(true){
        bool found = false;
        vector<bool> to_delete(n, false);
        for(int i=1; i<n-1; ++i){
            if(s[i] != s[i-1] && s[i] != s[i+1]){
                to_delete[i] = true;
                found = true;
            }
        }
        if(s.size() > 1){
            if(s[0] != s[1]){
                to_delete[0] = true;
                found = true;
            }
            if(s[n-1] != s[n-2]){
                to_delete[n-1] = true;
                found = true;
            }
        }
        if(!found) break;
        string new_s;
        for(int i=0; i<n; ++i){
            if(!to_delete[i]){
                new_s += s[i];
            }
        }
        s = new_s;
        n = s.size();
        operations++;
    }
    cout << operations << "\n";
}