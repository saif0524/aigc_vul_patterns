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
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i=0;i<n;i++) cin >> grid[i];
    
    vector<bool> row_used(n, false);
    vector<bool> col_used(m, false);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == '#'){
                bool can_be_colored = false;
                for(int k=i;k<n;k++){
                    if(!row_used[k]){
                        for(int l=j;l<m;l++){
                            if(!col_used[l] && grid[k][l] == '#'){
                                can_be_colored = true;
                                row_used[k] = true;
                                col_used[l] = true;
                            }
                        }
                    }
                }
                if(!can_be_colored){
                    cout << "No";
                    return 0;
                }
            }
        }
    }
    cout << "Yes";
}