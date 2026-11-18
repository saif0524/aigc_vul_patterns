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
    string password;
    cin >> password;
    int n;
    cin >> n;
    set<string> words;
    for(int i=0;i<n;i++){
        string word;
        cin >> word;
        words.insert(word);
    }
    for(auto it1 = words.begin(); it1 != words.end(); ++it1){
        for(auto it2 = words.begin(); it2 != words.end(); ++it2){
            string combined = *it1 + *it2;
            if(combined.find(password) != string::npos){
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}