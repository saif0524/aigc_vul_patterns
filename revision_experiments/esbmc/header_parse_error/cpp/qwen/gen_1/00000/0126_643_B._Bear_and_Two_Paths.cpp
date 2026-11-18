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
    int n, k;
    cin >> n >> k;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(k < 2*n-2){
        cout << -1;
        return 0;
    }
    vector<int> path1(n);
    vector<int> path2(n);
    path1[0] = a;
    path1[n-1] = b;
    path2[0] = c;
    path2[n-1] = d;
    int pos = 1;
    vector<bool> used(n+1, false);
    used[a] = true;
    used[b] = true;
    used[c] = true;
    used[d] = true;
    for(int i=1;i<=n;i++){
        if(!used[i]){
            path1[pos] = i;
            used[i] = true;
            pos++;
        }
    }
    pos = 1;
    for(int i=1;i<=n;i++){
        if(!used[i]){
            path2[pos] = i;
            used[i] = true;
            pos++;
        }
    }
    for(int i=1;i<=n-1;i++){
        if(path1[i] == path2[i]){
            swap(path2[i], path2[n-1]);
        }
    }
    for(int i=0;i<n;i++){
        cout << path1[i] << " ";
    }
    cout << "\n";
    for(int i=0;i<n;i++){
        cout << path2[i] << " ";
    }
}