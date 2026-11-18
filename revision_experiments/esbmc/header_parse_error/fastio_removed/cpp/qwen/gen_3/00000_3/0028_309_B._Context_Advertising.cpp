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
    int n, r, c;
    cin >> n >> r >> c;
    vector<string> words(n);
    for(auto &word : words) cin >> word;
    int max_words = 0, start = 0;
    int current_words = 0, current_length = 0;
    for(int i = 0; i < n; ++i){
        if(current_length + words[i].size() + (current_words > 0) > c){
            if(current_words > max_words){
                max_words = current_words;
                start = i - current_words;
            }
            while(current_length + words[i].size() + (current_words > 0) > c){
                current_length -= words[start].size() + (current_words > 1);
                start++;
                current_words--;
            }
        }
        current_length += words[i].size() + (current_words > 0);
        current_words++;
    }
    if(current_words > max_words){
        max_words = current_words;
        start = n - current_words;
    }
    int printed_lines = 0, line_length = 0;
    for(int i = start; i < start + max_words; ++i){
        if(line_length + words[i].size() + (line_length > 0) > c || printed_lines == r){
            cout << "\n";
            printed_lines++;
            line_length = 0;
        }
        if(line_length > 0) cout << " ";
        cout << words[i];
        line_length += words[i].size() + (line_length > 0);
    }
    for(; printed_lines < r; ++printed_lines){
        cout << "\n";
    }
}