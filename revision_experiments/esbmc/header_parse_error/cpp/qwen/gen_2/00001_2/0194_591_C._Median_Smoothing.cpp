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
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    vector<int> b(n);
    b = a;
    int steps = 0;
    bool changed = true;
    while(changed){
        changed = false;
        vector<int> c(n);
        c[0] = a[0];
        c[n-1] = a[n-1];
        for(int i=1;i<n-1;i++){
            int x = a[i-1], y = a[i], z = a[i+1];
            vector<int> tmp = {x, y, z};
            sort(tmp.begin(), tmp.end());
            c[i] = tmp[1];
            if(c[i] != b[i]) changed = true;
        }
        if(!changed) break;
        a = c;
        b = c;
        steps++;
    }
    if(steps == 0){
        cout << 0 << "\n";
        for(auto x: a) cout << x << " ";
        cout << "\n";
    }
    else{
        bool stable = true;
        while(true){
            vector<int> c(n);
            c[0] = a[0];
            c[n-1] = a[n-1];
            for(int i=1;i<n-1;i++){
                int x = a[i-1], y = a[i], z = a[i+1];
                vector<int> tmp = {x, y, z};
                sort(tmp.begin(), tmp.end());
                c[i] = tmp[1];
            }
            if(c == a) break;
            a = c;
            steps++;
        }
        cout << steps << "\n";
        for(auto x: a) cout << x << " ";
        cout << "\n";
    }
}