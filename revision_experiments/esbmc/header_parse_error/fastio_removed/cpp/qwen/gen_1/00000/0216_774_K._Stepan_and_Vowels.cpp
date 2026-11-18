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
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n == 0){
        cout << s;
        return 0;
    }
    string result;
    result += s[0];
    for(int i = 1; i < n; ++i){
        if(s[i] == s[i-1] && (s[i] == 'e' || s[i] == 'o')){
            int count = 1;
            while(i < n && s[i] == s[i-1]){
                ++count;
                ++i;
            }
            if(count == 2){
                result += s[i-1];
                result += s[i-1];
            }
            else{
                result += s[i-1];
                --i;
            }
        }
        else if(i > 1 && s[i] == s[i-1] && s[i] == s[i-2]){
            continue;
        }
        else{
            result += s[i];
        }
    }
    cout << result;
}