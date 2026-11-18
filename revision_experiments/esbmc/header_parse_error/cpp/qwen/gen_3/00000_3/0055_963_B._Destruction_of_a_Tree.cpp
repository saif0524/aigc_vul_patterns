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
    vector<int> p(n+1);
    vector<int> degree(n+1, 0);
    for(int i=1;i<=n;i++){
        cin >> p[i];
        if(p[i] != 0){
            degree[i]++;
            degree[p[i]]++;
        }
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(degree[i] % 2 == 0 && degree[i] > 0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans.push_back(u);
        degree[u] = 0;
        if(p[u] != 0){
            degree[p[u]]--;
            if(degree[p[u]] % 2 == 0 && degree[p[u]] > 0){
                q.push(p[u]);
            }
        }
    }
    if(ans.size() == n){
        cout << "YES\n";
        for(int x : ans){
            cout << x << "\n";
        }
    }
    else{
        cout << "NO\n";
    }
}