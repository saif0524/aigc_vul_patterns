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
    vector<char> compressed;
    vector<int> freq;
    compressed.push_back(s[0]);
    freq.push_back(1);
    for(int i=1;i<n;i++){
        if(s[i] == compressed.back()){
            freq.back()++;
        }
        else{
            compressed.push_back(s[i]);
            freq.push_back(1);
        }
    }
    int m = compressed.size();
    long long even=0, odd=0;
    for(int i=0;i<m;i++){
        long long f = freq[i];
        odd += (f*(f+1))/2;
        even += (f*(f-1))/2;
        if(i>0){
            if(compressed[i] == compressed[i-1]){
                long long mf = min(freq[i-1], freq[i]);
                even += (mf*(mf-1))/2;
            }
        }
    }
    cout << even << " " << odd;
}