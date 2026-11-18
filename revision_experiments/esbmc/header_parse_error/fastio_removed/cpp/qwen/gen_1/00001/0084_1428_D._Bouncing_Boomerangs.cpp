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
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    vector<pair<int,int>> targets;
    vector<int> rowcnt(n+1, 0);
    for(int c=1;c<=n;c++){
        if(a[c-1] == 3){
            if(rowcnt[1] >= 2 || rowcnt[2] >= 2){
                cout << "-1\n";
                return 0;
            }
            targets.emplace_back(1,c);
            targets.emplace_back(2,c);
            rowcnt[1]++;
            rowcnt[2]++;
            if(rowcnt[1] >= 2 || rowcnt[n] >= 2){
                cout << "-1\n";
                return 0;
            }
            targets.emplace_back(n,c);
            rowcnt[n]++;
        }
        else if(a[c-1] == 2){
            if(rowcnt[1] >= 2 || rowcnt[n] >= 2){
                cout << "-1\n";
                return 0;
            }
            targets.emplace_back(1,c);
            targets.emplace_back(n,c);
            rowcnt[1]++;
            rowcnt[n]++;
        }
        else if(a[c-1] == 1){
            bool placed = false;
            for(int r=1;r<=n;r++){
                if(rowcnt[r] < 2){
                    targets.emplace_back(r,c);
                    rowcnt[r]++;
                    placed = true;
                    break;
                }
            }
            if(!placed){
                cout << "-1\n";
                return 0;
            }
        }
    }
    cout << targets.size() << "\n";
    for(auto &[r,c]: targets){
        cout << r << " " << c << "\n";
    }
}