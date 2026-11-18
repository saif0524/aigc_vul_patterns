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

const int MAXN = 200005;
const int MAXA = 500005;

vector<int> factors[MAXA];
int counts[MAXA];
int totalPairs = 0;

void precomputeFactors() {
    for (int i = 1; i < MAXA; i++) {
        for (int j = i; j < MAXA; j += i) {
            factors[j].push_back(i);
        }
    }
}

int main(){
    ((void)0);
    ((void)0);
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    
    precomputeFactors();
    
    for(int i=0;i<q;i++){
        int x;
        cin >> x;
        x--;
        
        for(auto f: factors[a[x]]){
            if(counts[f] > 0){
                totalPairs -= (counts[f] -1);
            }
            counts[f]++;
            if(counts[f] > 1){
                totalPairs += (counts[f] -1);
            }
        }
        
        cout << totalPairs << "\n";
    }
}