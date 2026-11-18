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
    unordered_map<string, char> mp = {
        {"31", 'a'}, {"34", 'b'}, {"36", 'c'}, {"13", 'd'}, {"15", 'e'}, {"33", 'f'}, {"16", 'g'}, {"55", 'h'}, {"35", 'i'}, {"45", 'j'},
        {"43", 'k'}, {"51", 'l'}, {"44", 'm'}, {"56", 'n'}, {"53", 'o'}, {"25", 'p'}, {"54", 'q'}, {"12", 'r'}, {"26", 's'},
        {"52", 't'}, {"23", 'u'}, {"65", 'v'}, {"14", 'w'}, {"42", 'x'}, {"24", 'y'}, {"22", 'z'}, {"41", '.'}, {"61", '?'},
        {"46", '!'}, {"63", ' '}
    };
    
    string line;
    while(getline(cin, line)){
        if(line.empty()) continue;
        int n = line.size();
        if(n % 2 != 0){
            cout << "NA\n";
            continue;
        }
        bool valid = true;
        string res = "";
        for(int i = 0; i < n; i += 2){
            string two = line.substr(i, 2);
            if(mp.find(two) == mp.end()){
                valid = false;
                break;
            }
            res += mp[two];
        }
        if(valid) cout << res << "\n";
        else cout << "NA\n";
    }
}