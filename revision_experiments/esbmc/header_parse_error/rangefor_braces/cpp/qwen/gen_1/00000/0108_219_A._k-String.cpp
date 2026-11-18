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
    int k;
    string s;
    cin >> k >> s;
    int n = s.size();
    if(n % k != 0){
        cout << "-1";
        return 0;
    }
    int len = n / k;
    vector<int> freq(26, 0);
    for(char c : s) { freq[c - 'a']++; }
    for(int i = 0; i < 26; i++){
        if(freq[i] % k != 0){
            cout << "-1";
            return 0;
        }
        freq[i] /= k;
    }
    string result;
    for(int i = 0; i < len; i++){
        for(int j = 0; j < 26; j++){
            if(freq[j] > 0){
                result += (char)('a' + j);
                freq[j]--;
            }
        }
    }
    for(int i = 0; i < k; i++) cout << result;
}