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
    int t;
    cin >> t;
    while(t--){
        int k, n, m;
        cin >> k >> n >> m;
        vector<int> a(n), b(m);
        for(int &x: a) cin >> x;
        for(int &x: b) cin >> x;
        vector<int> ans;
        int ai = 0, bi = 0;
        int cur_lines = k;
        while(ai < n || bi < m){
            bool added = false;
            if(ai < n && (a[ai] == 0 || a[ai] <= cur_lines)){
                ans.push_back(a[ai]);
                if(a[ai] == 0) cur_lines++;
                ai++;
                added = true;
            }
            if(!added && bi < m && (b[bi] == 0 || b[bi] <= cur_lines)){
                ans.push_back(b[bi]);
                if(b[bi] == 0) cur_lines++;
                bi++;
            }
            if(!added && (ai >= n || (a[ai] > cur_lines && (bi >= m || b[bi] > cur_lines)))){
                break;
            }
        }
        if(ai < n || bi < m){
            cout << "-1\n";
        }
        else{
            for(int i=0; i<ans.size(); i++){
                if(i) cout << " ";
                cout << ans[i];
            }
            cout << "\n";
        }
    }
}