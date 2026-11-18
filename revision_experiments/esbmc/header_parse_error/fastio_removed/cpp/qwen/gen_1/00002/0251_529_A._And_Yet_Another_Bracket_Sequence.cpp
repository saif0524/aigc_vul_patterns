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

bool is_valid(const string& s) {
    int bal = 0;
    for (char c : s) {
        if (c == '(') bal++;
        else bal--;
        if (bal < 0) return false;
    }
    return bal == 0;
}

string fix_brackets(const string& s) {
    int n = s.size();
    int bal = 0;
    int open_excess = 0, close_excess = 0;
    for (char c : s) {
        if (c == '(') bal++;
        else bal--;
        if (bal < 0) {
            bal = 0;
            close_excess++;
        }
    }
    open_excess = bal;
    
    string fixed;
    bal = 0;
    for (char c : s) {
        if (c == '(') {
            if (open_excess > 0) {
                open_excess--;
            } else {
                fixed += c;
                bal++;
            }
        } else {
            if (bal > 0) {
                fixed += c;
                bal--;
            } else {
                close_excess--;
            }
        }
    }
    return fixed;
}

int main(){
    ((void)0);
    ((void)0);
    string s;
    cin >> s;
    s = fix_brackets(s);
    
    string best = s;
    for(int i=0; i<s.size(); i++){
        rotate(s.rbegin(), s.rbegin()+1, s.rend());
        s = fix_brackets(s);
        if(s < best) best = s;
    }
    cout << best;
}