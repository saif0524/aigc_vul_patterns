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
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> c(m);
    int total_length = 0;
    for(int &x: c){
        cin >> x;
        total_length += x;
    }
    
    vector<int> platform(n+2, 0);
    int current_pos = 1;
    for(int i=0; i<m; i++){
        for(int j=0; j<c[i]; j++){
            platform[current_pos++] = i+1;
        }
    }
    
    vector<bool> reachable(n+2, false);
    reachable = true;
    queue<int> q;
    q.push(0);
    
    while(!q.empty()){
        int pos = q.front();
        q.pop();
        for(int next_pos = pos+1; next_pos <= min(pos+d, n+1); next_pos++){
            if(platform[next_pos] ==0) continue;
            if(reachable[next_pos]) continue;
            reachable[next_pos] = true;
            q.push(next_pos);
        }
    }
    
    if(!reachable[n+1]){
        cout << "NO\n";
        return 0;
    }
    
    cout << "YES\n";
    for(int i=1; i<=n; i++){
        cout << platform[i] << (i==n?"\n":" ");
    }
}