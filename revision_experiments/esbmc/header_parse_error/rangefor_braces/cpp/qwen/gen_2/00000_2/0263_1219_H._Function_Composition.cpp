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

const int MAXN = 2e5 + 5;

int main(){
    ((void)0);
    ((void)0);
    
    int N;
    cin >> N;
    vector<long long> A(N);
    for(auto &x : A) { cin >> x, x--; }
    
    vector<vector<int>> cycles;
    vector<int> visited(N, 0);
    
    for(int i=0; i<N; i++){
        if(!visited[i]){
            vector<int> cycle;
            int u = i;
            while(!visited[u]){
                visited[u] = 1;
                cycle.push_back(u);
                u = A[u];
            }
            bool found = false;
            for(int j=0; j<cycle.size(); j++){
                if(cycle[j] == u){
                    found = true;
                    cycles.push_back(vector<int>(cycle.begin() + j, cycle.end()));
                    break;
                }
            }
            if(!found) cycles.push_back(cycle);
        }
    }
    
    int Q;
    cin >> Q;
    while(Q--){
        long long m;
        int y;
        cin >> m >> y;
        y--;
        bool found = false;
        for(auto &cycle : cycles){
            auto it = find(cycle.begin(), cycle.end(), y);
            if(it != cycle.end()){
                int idx = it - cycle.begin();
                int len = cycle.size();
                if(m < len){
                    if(cycle[m] == y) cout << 1;
                    else cout << 0;
                }
                else{
                    if((m - idx) % len == 0) cout << 1;
                    else cout << 0;
                }
                found = true;
                break;
            }
        }
        if(!found) cout << 0;
        cout << "\n";
    }
}