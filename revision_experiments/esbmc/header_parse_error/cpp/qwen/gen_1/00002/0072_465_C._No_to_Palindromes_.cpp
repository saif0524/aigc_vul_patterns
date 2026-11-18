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
    int n, p;
    string s;
    cin >> n >> p >> s;
    for(int i = n-1; i >= 0; i--){
        if(s[i] < 'a' + p - 1){
            s[i]++;
            bool valid = true;
            for(int j = 1; j <= i && valid; j++){
                if(s[i] == s[i-j]) valid = false;
                if(i-j-1 >= 0 && s[i-j] == s[i-j-1]) valid = false;
            }
            if(valid){
                for(int j = i+1; j < n; j++){
                    for(char c = 'a'; c <= 'a'+p-1; c++){
                        bool can_use = true;
                        for(int k = 1; k <= j && can_use; k++){
                            if(c == s[j-k]) can_use = false;
                            if(j-k-1 >= 0 && s[j-k-1] == c) can_use = false;
                        }
                        if(can_use){
                            s[j] = c;
                            break;
                        }
                    }
                }
                cout << s;
                return 0;
            }
        }
    }
    cout << "NO";
}