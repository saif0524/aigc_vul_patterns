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
    vector<int> parent(n+1, -1);
    vector<int> root, changes;
    for(int i = 0; i < n; i++){
        if(a[i] == i + 1){
            root.push_back(i+1);
        }
        else{
            int u = a[i], v = i + 1;
            while(u != -1){
                if(u == v){
                    changes.push_back(i+1);
                    break;
                }
                if(parent[u] != -1){
                    changes.push_back(i+1);
                    break;
                }
                parent[u] = v;
                u = a[u - 1];
            }
        }
    }
    int cnt_changes = (int)changes.size();
    if(root.empty()){
        root.push_back(1);
        while((int)root.size() < n - cnt_changes + 1){
            for(int i = 0; i < n; i++){
                if(a[i] == root.back()){
                    root.push_back(i + 1);
                    break;
                }
            }
        }
    }
    while((int)root.size() < n - cnt_changes + 1){
        root.push_back(root.back());
    }
    for(int i = 0; i < cnt_changes; i++){
        a[changes[i] - 1] = root.back();
        root.pop_back();
    }
    cout << cnt_changes << "\n";
    for(auto x: a) cout << x << " ";
    cout << "\n";
}