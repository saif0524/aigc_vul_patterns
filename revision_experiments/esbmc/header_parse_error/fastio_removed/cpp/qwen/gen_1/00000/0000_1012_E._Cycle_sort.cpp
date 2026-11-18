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
    for(auto &x: a) cin >> x;
    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());
    vector<bool> visited(n, false);
    int ops = 0;
    vector<vector<int>> operations;
    for(int i=0;i<n;++i){
        if(!visited[i]){
            if(a[i] == sorted_a[i]){
                continue;
            }
            vector<int> cycle;
            int j = i;
            while(!visited[j]){
                visited[j] = true;
                cycle.push_back(j+1);
                j = find(a.begin(), a.end(), sorted_a[j]) - a.begin();
            }
            if(cycle.size() > 0){
                operations.push_back(cycle);
                ops++;
            }
        }
    }
    int total_length = 0;
    for(auto &op: operations){
        total_length += op.size();
    }
    if(total_length > s){
        cout << "-1\n";
    }
    else{
        cout << ops << "\n";
        for(auto &op: operations){
            cout << op.size() << "\n";
            for(auto &x: op){
                cout << x << " ";
            }
            cout << "\n";
        }
    }
}