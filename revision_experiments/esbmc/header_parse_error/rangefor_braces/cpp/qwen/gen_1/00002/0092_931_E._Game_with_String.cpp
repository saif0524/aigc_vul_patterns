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
    string doubled_s = s + s;
    vector<int> freq(26, 0);
    for(char c : s) { freq[c - 'a']++; }
    double total_prob = 0.0;

    for(int i = 0; i < n; i++){
        set<string> unique_shifts;
        for(int j = 0; j < n; j++){
            string shift = doubled_s.substr(j, n);
            if(shift[0] == s[i]){
                unique_shifts.insert(shift);
            }
        }
        if(unique_shifts.size() == 1){
            total_prob += 1.0;
            continue;
        }
        for(int j = 1; j < n; j++){
            set<string> possible_shifts;
            for(string &shift : unique_shifts){
                if(possible_shifts.size() > 1) break;
                possible_shifts.insert(shift);
            }
            unique_shifts.clear();
            for(string &shift : possible_shifts){
                if(shift[j] == s[(i+j) % n]){
                    unique_shifts.insert(shift);
                }
            }
            if(unique_shifts.size() == 1){
                total_prob += 1.0 / n;
                break;
            }
        }
    }

    printf("%.15f\n", total_prob / n);
    return 0;
}