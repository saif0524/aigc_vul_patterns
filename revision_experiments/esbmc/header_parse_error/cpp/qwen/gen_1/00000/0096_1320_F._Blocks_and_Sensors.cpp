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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> fxz(m, vector<int>(k)), bxz(m, vector<int>(k));
    vector<vector<int>> fyz(n, vector<int>(k)), byz(n, vector<int>(k));
    vector<vector<int>> fzy(n, vector<int>(m)), bzy(n, vector<int>(m));
    for(int i=0; i<m; i++){
        for(int j=0; j<k; j++) cin >> fxz[i][j];
    }
    cin.ignore();
    for(int i=0; i<m; i++){
        for(int j=0; j<k; j++) cin >> bxz[i][j];
    }
    cin.ignore();
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++) cin >> fyz[i][j];
    }
    cin.ignore();
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++) cin >> byz[i][j];
    }
    cin.ignore();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin >> fzy[i][j];
    }
    cin.ignore();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin >> bzy[i][j];
    }
    vector<vector<vector<int>>> ans(n, vector<vector<int>>(m, vector<int>(k, 0)));
    for(int x=0; x<n; x++){
        for(int y=0; y<m; y++){
            for(int z=0; z<k; z++){
                if(fxz[y][z] && (x==0 || !ans[x-1][y][z])) ans[x][y][z] = fxz[y][z];
                if(bxz[y][z] && (x==n-1 || !ans[x+1][y][z])) ans[x][y][z] = bxz[y][z];
                if(fyz[x][z] && (y==0 || !ans[x][y-1][z])) ans[x][y][z] = fyz[x][z];
                if(byz[x][z] && (y==m-1 || !ans[x][y+1][z])) ans[x][y][z] = byz[x][z];
                if(fzy[x][y] && (z==0 || !ans[x][y][z-1])) ans[x][y][z] = fzy[x][y];
                if(bzy[x][y] && (z==k-1 || !ans[x][y][z+1])) ans[x][y][z] = bzy[x][y];
                if(fxz[y][z] && x>0 && ans[x-1][y][z] && ans[x-1][y][z] != fxz[y][z]) {cout << "-1\n"; return 0;}
                if(bxz[y][z] && x<n-1 && ans[x+1][y][z] && ans[x+1][y][z] != bxz[y][z]) {cout << "-1\n"; return 0;}
                if(fyz[x][z] && y>0 && ans[x][y-1][z] && ans[x][y-1][z] != fyz[x][z]) {cout << "-1\n"; return 0;}
                if(byz[x][z] && y<m-1 && ans[x][y+1][z] && ans[x][y+1][z] != byz[x][z]) {cout << "-1\n"; return 0;}
                if(fzy[x][y] && z>0 && ans[x][y][z-1] && ans[x][y][z-1] != fzy[x][y]) {cout << "-1\n"; return 0;}
                if(bzy[x][y] && z<k-1 && ans[x][y][z+1] && ans[x][y][z+1] != bzy[x][y]) {cout << "-1\n"; return 0;}
            }
        }
    }
    for(int x=0; x<n; x++){
        for(int y=0; y<m; y++){
            for(int z=0; z<k; z++){
                cout << ans[x][y][z] << " ";
            }
        }
    }
}