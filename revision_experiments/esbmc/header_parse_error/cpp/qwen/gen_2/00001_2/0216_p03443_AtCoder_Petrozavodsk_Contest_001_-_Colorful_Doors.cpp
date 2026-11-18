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
    int N;
    cin >> N;
    string s;
    cin >> s;
    vector<int> left(N+1, -1), right(N+1, -1);
    vector<int> ans(2*N);
    int pos = 0;
    set<int> unused, used;

    for(int i=1; i<=N; i++){
        unused.insert(i);
    }

    for(int i=0; i<2*N-1; i++){
        if(s[i] == '1'){
            int col = -1;
            if(!unused.empty()){
                col = *unused.begin();
                unused.erase(unused.begin());
            }
            else if(!used.empty()){
                col = *used.rbegin();
                used.erase(--used.end());
            }
            if(col == -1){
                cout << "No\n";
                return 0;
            }
            if(left[col] == -1){
                left[col] = pos;
            }
            else{
                right[col] = pos;
            }
            ans[pos++] = col;
            used.insert(col);
        }
        else{
            if(left.empty()){
                cout << "No\n";
                return 0;
            }
            int col = left.rbegin()->first;
            left.erase(--left.end());
            right[col] = pos;
            ans[pos++] = col;
        }
    }

    for(int i=1; i<=N; i++){
        if(left[i] != -1 && right[i] != -1){
            continue;
        }
        cout << "No\n";
        return 0;
    }

    for(int i=0; i<N; i++){
        if(right[ans[i]] < left[ans[i+1]]){
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    for(int i=0; i<2*N; i++){
        cout << ans[i] << (i==2*N-1?'\n':' ');
    }
}