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
    int n, r, c;
    cin >> n >> r >> c;
    vector<string> words(n);
    for(auto &w: words) cin >> w;
    int max_len = 0;
    int best_start = 0;
    int best_end = 0;
    for(int start = 0; start < n; ++start){
        int end = start;
        int chars = 0;
        int lines = 1;
        while(end < n && lines <= r && chars + (end > start) + words[end].size() <= c){
            chars += (end > start) + words[end].size();
            if(chars + (end > start) + words[end].size() > c) ++lines;
            if(chars + (end > start) + words[end].size() > c) chars = words[end].size();
            end++;
        }
        if(end - start > max_len){
            max_len = end - start;
            best_start = start;
            best_end = end - 1;
        }
    }
    int current_chars = 0;
    int current_line = 1;
    for(int i = best_start; i <= best_end; ++i){
        if(current_chars + (i > best_start) + words[i].size() > c || current_line > r){
            cout << "\n";
            current_chars = 0;
            current_line++;
        }
        if(i > best_start) cout << " ";
        cout << words[i];
        current_chars += (i > best_start) + words[i].size();
    }
}