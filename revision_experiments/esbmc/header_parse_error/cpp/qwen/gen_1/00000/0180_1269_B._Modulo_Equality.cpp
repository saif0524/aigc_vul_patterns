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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    map<int, int> freqA, freqB;
    for(int i=0; i<n; i++){
        freqA[a[i]]++;
        freqB[b[i]]++;
    }
    for(int x=0; x<m; x++){
        bool valid = true;
        map<int, int> tempFreqA(freqA);
        for(auto &[bVal, bCount]: freqB){
            int aVal = (bVal - x + m) % m;
            if(tempFreqA[aVal] < bCount){
                valid = false;
                break;
            }
            tempFreqA[aVal] -= bCount;
        }
        if(valid){
            cout << x;
            return 0;
        }
    }
}