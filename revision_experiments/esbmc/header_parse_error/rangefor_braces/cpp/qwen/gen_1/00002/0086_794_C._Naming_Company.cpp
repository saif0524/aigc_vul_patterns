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
    string s, t;
    cin >> s >> t;
    int n = s.size();
    map<char, int> freq_s, freq_t;
    for(char c : s) { freq_s[c]++; }
    for(char c : t) { freq_t[c]++; }
    string res;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            bool found = false;
            for(char c = 'a'; c <= 'z'; c++){
                if(freq_s[c] > 0){
                    bool valid = true;
                    for(char x = c + 1; x <= 'z'; x++){
                        if(freq_t[x] > 0){
                            valid = false;
                            break;
                        }
                    }
                    if(valid){
                        res += c;
                        freq_s[c]--;
                        found = true;
                        break;
                    }
                }
            }
            if(!found){
                for(char c = 'z'; c >= 'a'; c--){
                    if(freq_s[c] > 0){
                        res += c;
                        freq_s[c]--;
                        break;
                    }
                }
            }
        }
        else{
            bool found = false;
            for(char c = 'z'; c >= 'a'; c--){
                if(freq_t[c] > 0){
                    bool valid = true;
                    for(char x = 'a'; x < c; x++){
                        if(freq_s[x] > 0){
                            valid = false;
                            break;
                        }
                    }
                    if(valid){
                        res += c;
                        freq_t[c]--;
                        found = true;
                        break;
                    }
                }
            }
            if(!found){
                for(char c = 'a'; c <= 'z'; c++){
                    if(freq_t[c] > 0){
                        res += c;
                        freq_t[c]--;
                        break;
                    }
                }
            }
        }
    }
    cout << res;
}