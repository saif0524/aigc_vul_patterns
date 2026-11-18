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
    string s;
    cin >> s;
    vector<int> l(n, 0), r(n, 0);
    for(int i=0; i<n; i++){
        int j = i, k = i;
        while(j>0 && k<n-1 && s[j-1] == s[k+1]){
            j--, k++;
        }
        l[i] = j, r[i] = k;
    }
    for(int i=n-1; i>=0; i--){
        int j = i, k = i;
        if(i>0 && s[i-1] == s[i]){
            j--, k++;
            while(j>0 && k<n-1 && s[j-1] == s[k+1]){
                j--, k++;
            }
        }
        l[i] = max(l[i], j), r[i] = max(r[i], k);
    }
    long long ans = 0;
    for(int i=0; i<n; i++){
        ans += r[i] - l[i] + 1 - (i-l[i]+1);
    }
    cout << ans;
}