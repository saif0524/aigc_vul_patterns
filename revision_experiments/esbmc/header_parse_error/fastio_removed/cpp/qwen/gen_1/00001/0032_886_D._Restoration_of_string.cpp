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
    int n;
    cin >> n;
    vector<string> s(n);
    for(auto &str: s) cin >> str;
    sort(s.begin(), s.end());
    do{
        string combined;
        for(auto &str: s) combined += str;
        bool valid = true;
        for(auto &str: s){
            int count = 0;
            size_t pos = combined.find(str);
            while(pos != string::npos){
                count++;
                pos = combined.find(str, pos + 1);
            }
            for(auto &other: s){
                if(other == str) continue;
                int otherCount = 0;
                size_t otherPos = combined.find(other);
                while(otherPos != string::npos){
                    otherCount++;
                    otherPos = combined.find(other, otherPos + 1);
                }
                if(otherCount > count){
                    valid = false;
                    break;
                }
            }
            if(!valid) break;
        }
        if(valid){
            cout << combined;
            return 0;
        }
    }while(next_permutation(s.begin(), s.end()));
    cout << "NO";
}