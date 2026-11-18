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
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<bool> rows(n+1, false), cols(m+1, false);
    for(int i=0; i<k; i++){
        int r, c;
        cin >> r >> c;
        rows[r] = true;
        cols[c] = true;
    }
    for(int i=0; i<q; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        bool protected_ = false;
        for(int r=x1; r<=x2 && !protected_; r++){
            if(rows[r]){
                protected_ = true;
            }
        }
        if(!protected_){
            for(int c=y1; c<=y2 && !protected_; c++){
                if(cols[c]){
                    protected_ = true;
                }
            }
        }
        cout << (protected_ ? "YES" : "NO") << "\n";
    }
}