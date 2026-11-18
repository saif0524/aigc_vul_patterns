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
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for(auto &x: a) cin >> x;
    for(int i=0; i<N-1; i++){
        if(K == 0) break;
        if(a[i] > a[i+1]){
            swap(a[i], a[i+1]);
            K--;
        }
    }
    for(int i=1; i<N; i++){
        for(int j=i; j>0 && K>0 && a[j] < a[j-1]; j--){
            swap(a[j], a[j-1]);
            K--;
        }
    }
    for(auto x: a) cout << x << "\n";
}