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
    int n;
    cin >> n;
    vector<int> a(n*n);
    for(auto &x: a) { cin >> x; }
    
    if(n&1){
        int mid = n/2;
        int freq[1001] = {0};
        for(int x: a) { freq[x]++; }
        
        for(int x: a){
            if(freq[x]==0) continue;
            if(x == a[mid*n+mid]){
                if(freq[x] % 2 != 0) {
                    freq[x] = 0;
                    continue;
                } else {
                    freq[x] = 0;
                    continue;
                }
            }
            if(freq[x] < 4) {
                cout << "NO";
                return 0;
            }
            freq[x] -= 4;
        }
        
        cout << "YES\n";
        vector<vector<int>> mat(n, vector<int>(n));
        int idx = 0;
        
        for(int i=0; i<=mid; i++){
            for(int j=0; j<=mid; j++){
                while(freq[a[idx]] == 0) idx++;
                freq[a[idx]] -= 2;
                mat[i][j] = mat[n-i-1][j] = mat[i][n-j-1] = mat[n-i-1][n-j-1] = a[idx];
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
    }
    else{
        int freq[1001] = {0};
        for(int x: a) { freq[x]++; }
        
        for(int x: a){
            if(freq[x]==0) continue;
            if(freq[x] % 4 != 0) {
                cout << "NO";
                return 0;
            }
            freq[x] = 0;
        }
        
        cout << "YES\n";
        vector<vector<int>> mat(n, vector<int>(n));
        int idx = 0;
        
        for(int i=0; i<n/2; i++){
            for(int j=0; j<n/2; j++){
                while(freq[a[idx]] == 0) idx++;
                freq[a[idx]] -= 4;
                mat[i][j] = mat[n-i-1][j] = mat[i][n-j-1] = mat[n-i-1][n-j-1] = a[idx];
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
    }
}