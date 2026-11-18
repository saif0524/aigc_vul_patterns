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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    vector<int> right(n, -1);
    for(int i=n-1; i>=0; i--){
        if(a[i] == 0) continue;
        for(int j=i+1; j<n; j++){
            if(a[i] & a[j]){
                right[i] = j;
                break;
            }
        }
    }
    while(q--){
        int x, y;
        cin >> x >> y;
        x--, y--;
        while(x != -1 && x < y){
            if(x == y){
                cout << "Shi\n";
                break;
            }
            x = right[x];
        }
        if(x == -1 || x != y) cout << "Fou\n";
    }
}