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
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for(auto &x: a) { cin >> x; }
    vector<int> pos(n);
    for(int i=0;i<n;i++) pos[a[i]-1]=i;
    vector<bool> vis(n);
    int ans = 0;
    vector<vector<int>> cycles;
    for(int i=0;i<n;i++){
        if(vis[i] || pos[i]==i) continue;
        int j = i;
        vector<int> cycle;
        int len = 0;
        while(!vis[j]){
            vis[j] = true;
            cycle.push_back(j+1);
            j = pos[j];
            len++;
        }
        ans++;
        if(len > s){
            cout << "-1";
            return 0;
        }
        s -= len;
        cycles.push_back(cycle);
    }
    cout << ans << "\n";
    for(auto &c: cycles){
        cout << c.size() << "\n";
        for(auto x: c) { cout << x << " "; }
        cout << "\n";
    }
}