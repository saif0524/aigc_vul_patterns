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

const int MOD = 1e9 + 7;

int main(){
    ((void)0);
    ((void)0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vectors(n);
    for(int i=0; i<n; i++){
        int k;
        cin >> k;
        vectors[i].resize(k);
        for(int &x : vectors[i]) cin >> x, x--;
    }

    bitset<500005> basis[m];
    vector<int> indices;
    for(int i=0; i<n; i++){
        bitset<500005> vec(m);
        for(int x : vectors[i]) vec[x] = 1;
        bool independent = true;
        for(int j=0; j<m; j++){
            if(vec[j] && basis[j].count()){
                vec ^= basis[j];
            }
        }
        for(int j=0; j<m && independent; j++){
            if(!basis[j].count()){
                basis[j] = vec;
                indices.push_back(i);
                independent = false;
            }
        }
    }

    long long size_T = 1;
    for(int j=0; j<m; j++){
        if(basis[j].count()){
            size_T = (size_T * 2) % MOD;
        }
    }

    sort(indices.begin(), indices.end());
    cout << size_T << " " << indices.size() << "\n";
    for(int idx : indices){
        cout << idx + 1 << " ";
    }
}