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
    int n;
    cin >> n;
    vector<int> p(n, 0);
    vector<int> max_bits(n, 0);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j) continue;
            cout << "? " << i+1 << " " << j+1 << endl;
            fflush(stdout);
            int val;
            cin >> val;
            if(val == -1) return 0;
            max_bits[i] = max(max_bits[i], val);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(max_bits[i] == (max_bits[i]|max_bits[j])){
                p[j] = i;
                break;
            }
        }
    }
    cout << "!";
    for(int x : p) cout << " " << x;
    cout << endl;
    return 0;
}