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

const int MOD = 1000000007;

int main(){
    ((void)0);
    ((void)0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n, -1));
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a][b] = c;
        adj[b][a] = c;
    }
    long long lo = 1, hi = 1 << (n*(n-1)/2);
    auto check = [&](long long mask){
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                for(int k=0; k<j; k++){
                    long long x = mask & (1LL << (i*n + j));
                    long long y = mask & (1LL << (j*n + k));
                    long long z = mask & (1LL << (k*n + i));
                    int a = (adj[i][j] != -1 ? adj[i][j] : (x ? 1 : 0));
                    int b = (adj[j][k] != -1 ? adj[j][k] : (y ? 1 : 0));
                    int c = (adj[k][i] != -1 ? adj[k][i] : (z ? 1 : 0));
                    if((a && b && c) || (a && b && !c) || (a && !b && c) || (!a && b && c))
                        return false;
                }
            }
        }
        return true;
    };
    for(long long i=0; i<hi; i++){
        if(check(i)){
            lo++;
        }
    }
    cout << (lo-1) % MOD;
}