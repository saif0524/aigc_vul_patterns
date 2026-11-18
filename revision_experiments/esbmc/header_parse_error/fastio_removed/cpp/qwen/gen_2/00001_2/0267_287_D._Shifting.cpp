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
    vector<int> p(n);
    for(int i=0;i<n;i++) p[i] = i+1;
    for(int k=2;k<=n;k++){
        vector<int> f(n);
        int r = 1;
        while(pow(k, r) <= n) r++;
        r--;
        int pos = 0;
        for(int j=1;j<=r;j++){
            int len = pow(k, j);
            for(int x=1;x<=len;x++){
                f[pos++] = p[x + (len-1) * (j-1)];
            }
        }
        int rem = n - pow(k, r);
        for(int x=1;x<=rem;x++){
            f[pos++] = p[pow(k, r) + x - 1];
        }
        p = f;
    }
    for(int i=0;i<n;i++) cout << p[i] << (i < n-1 ? ' ' : '\n');
}