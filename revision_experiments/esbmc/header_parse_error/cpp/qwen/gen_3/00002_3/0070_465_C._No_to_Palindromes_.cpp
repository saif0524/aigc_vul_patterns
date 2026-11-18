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

bool is_palindrome(const string& s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

bool is_tolerable(const string& s) {
    for (int i = 0; i + 1 < s.size(); ++i) {
        if (is_palindrome(s, i, i + 1)) return false;
        if (i + 2 < s.size() && is_palindrome(s, i, i + 2)) return false;
    }
    return true;
}

int main(){
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    for(int i = n - 1; i >= 0; --i){
        if(s[i] < ('a' + p - 1)){
            char next_char = s[i] + 1;
            while(next_char <= 'a' + p - 1){
                s[i] = next_char;
                if(is_tolerable(s)){
                    cout << s;
                    return 0;
                }
                next_char++;
            }
        }
        s[i] = 'a';
    }
    cout << "NO";
}