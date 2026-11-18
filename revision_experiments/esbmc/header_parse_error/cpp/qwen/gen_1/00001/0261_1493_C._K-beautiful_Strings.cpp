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
    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        bool found = false;
        for(int i = n-1; i >= 0; --i){
            if(s[i] < 'z'){
                char next_char = s[i] + 1;
                string new_s = s.substr(0, i) + next_char;
                string remaining = string(n - i - 1, 'a');
                new_s += remaining;
                int freq[26] = {0};
                for(char c : new_s){
                    freq[c - 'a']++;
                }
                bool valid = true;
                for(int f : freq){
                    if(f % k != 0){
                        valid = false;
                        break;
                    }
                }
                if(valid){
                    found = true;
                    cout << new_s << "\n";
                    break;
                }
            }
        }
        if(!found){
            cout << "-1\n";
        }
    }
}