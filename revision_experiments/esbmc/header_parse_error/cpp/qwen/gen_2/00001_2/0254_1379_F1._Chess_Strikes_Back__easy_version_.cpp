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
    int n, m, q;
    cin >> n >> m >> q;
    vector<bool> row(1 << n, true);
    vector<bool> col(1 << m, true);
    int total = (1 << n) * (1 << m) / 2;
    int used = 0;
    while(q--){
        int i, j;
        cin >> i >> j;
        i--, j--;
        int row_ind = i >> 1;
        int col_ind = j >> 1;
        if((i + j) % 2 == 0){
            if(row[row_ind] && col[col_ind]){
                used++;
                if(used > total){
                    cout << "NO\n";
                }
                else{
                    int cnt = 0;
                    for(int k = 0; k < 2; k++){
                        for(int l = 0; l < 2; l++){
                            int ni = row_ind + k;
                            int nj = col_ind + l;
                            if(ni >= 0 && ni < (1 << n) && nj >= 0 && nj < (1 << m)){
                                if(!row[ni] || !col[nj]){
                                    cnt++;
                                }
                            }
                        }
                    }
                    if(cnt >= 3){
                        cout << "NO\n";
                    }
                    else{
                        cout << "YES\n";
                    }
                    if(cnt >= 3){
                        used--;
                    }
                }
                row[row_ind] = false;
                col[col_ind] = false;
            }
            else{
                cout << (used > total ? "NO\n" : "YES\n");
            }
        }
    }
}