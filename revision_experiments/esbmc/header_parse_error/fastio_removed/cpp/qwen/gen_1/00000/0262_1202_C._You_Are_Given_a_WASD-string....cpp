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
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        int mx_x=0, mn_x=0, mx_y=0, mn_y=0, x=0, y=0;
        for(char c: s){
            if(c == 'W') y--;
            else if(c == 'A') x--;
            else if(c == 'S') y++;
            else if(c == 'D') x++;
            mx_x = max(mx_x, x);
            mn_x = min(mn_x, x);
            mx_y = max(mx_y, y);
            mn_y = min(mn_y, y);
        }
        int best = (mx_x - mn_x + 1) * (mx_y - mn_y + 1);
        x=0, y=0;
        for(int i=0; i<(int)s.size();++i){
            int nmx_x=0, nmn_x=0, nmx_y=0, nmn_y=0;
            for(int j=0; j<(int)s.size();++j){
                if(i == j){
                    if('W' + 'A'+ 'S' + 'D' - s[j] == 'W'){
                        y--;
                    }
                    else if('W' + 'A'+ 'S' + 'D' - s[j] == 'A'){
                        x--;
                    }
                    else if('W' + 'A'+ 'S' + 'D' - s[j] == 'S'){
                        y++;
                    }
                    else if('W' + 'A'+ 'S' + 'D' - s[j] == 'D'){
                        x++;
                    }
                }
                else{
                    if(s[j] == 'W') y--;
                    else if(s[j] == 'A') x--;
                    else if(s[j] == 'S') y++;
                    else if(s[j] == 'D') x++;
                }
                nmx_x = max(nmx_x, x);
                nmn_x = min(nmn_x, x);
                nmx_y = max(nmx_y, y);
                nmn_y = min(nmn_y, y);
            }
            best = min(best, (nmx_x - nmn_x + 1) * (nmx_y - nmn_y + 1));
            x=0, y=0;
        }
        cout << best << "\n";
    }
}