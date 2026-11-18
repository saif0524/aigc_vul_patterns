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
    int n;
    cin >> n;
    vector<string> words(n);
    for(auto &w: words) cin >> w;
    string message;
    cin >> message;
    string pattern = "<3";
    int i = 0, j = 0;
    while(j < message.size()){
        bool matched = false;
        if(message.substr(j, 2) == pattern){
            j += 2;
            if(i < n){
                int k = j;
                while(k < message.size() && isalpha(message[k])){
                    k++;
                }
                if(message.substr(j, k - j) == words[i]){
                    j = k;
                    i++;
                    matched = true;
                }
            }
        }
        if(!matched){
            j++;
        }
    }
    if(i == n && message.substr(j) == pattern){
        cout << "yes";
    } else {
        cout << "no";
    }
}