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
    string s, t;
    cin >> s >> t;
    int n = s.size();
    vector<int> os(26, 0), it(26, 0);
    for(char c : s) { os[c - 'a']++; }
    for(char c : t) { it[c - 'a']++; }
    
    string res(n, '?');
    int turn = 0;
    for(int i = 0; i < n; ++i){
        if(turn == 0){
            for(int j = 0; j < 26; ++j){
                if(os[j] > 0){
                    bool ok = true;
                    for(int k = j + 1; k < 26; ++k){
                        if(it[k] > 0){
                            ok = false;
                            break;
                        }
                    }
                    if(ok){
                        res[i] = ('a' + j);
                        os[j]--;
                        turn = 1;
                        break;
                    }
                }
            }
        }
        else{
            for(int j = 25; j >= 0; --j){
                if(it[j] > 0){
                    bool ok = true;
                    for(int k = j - 1; k >= 0; --k){
                        if(os[k] > 0){
                            ok = false;
                            break;
                        }
                    }
                    if(ok){
                        res[i] = ('a' + j);
                        it[j]--;
                        turn = 0;
                        break;
                    }
                }
            }
        }
    }
    cout << res;
}