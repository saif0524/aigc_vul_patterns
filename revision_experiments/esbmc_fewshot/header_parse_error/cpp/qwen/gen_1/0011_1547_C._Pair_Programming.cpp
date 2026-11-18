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
    int t;
    cin >> t;
    while(t--){
        int k, n, m;
        cin >> k >> n >> m;
        vector<int> a(n), b(m);
        for(int &x: a) cin >> x;
        for(int &x: b) cin >> x;
        int i = 0, j = 0;
        int lines = k;
        vector<int> res;
        bool valid = true;
        while(i < n || j < m){
            bool added = false;
            if(i < n && (a[i] == 0 || a[i] <= lines)){
                res.push_back(a[i]);
                if(a[i] == 0) lines++;
                i++;
                added = true;
            }
            if(j < m && (b[j] == 0 || b[j] <= lines)){
                res.push_back(b[j]);
                if(b[j] == 0) lines++;
                j++;
                added = true;
            }
            if(!added){
                valid = false;
                break;
            }
        }
        if(valid && i == n && j == m){
            for(int x: res) cout << x << " ";
            cout << "\n";
        }
        else{
            cout << "-1\n";
        }
    }
}