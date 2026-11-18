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
    string s;
    cin >> N >> s;
    vector<int> left(N+1, -1), right(N+1, -1);
    vector<int> ans;
    stack<int> st;
    bool valid = true;
    
    for(int i=0;i<(2*N-1);i++){
        if(s[i] == '1'){
            if(st.empty()){
                valid = false;
                break;
            }
            right[st.top()] = i+1;
            left[i+2] = st.top();
            st.pop();
        }
        else{
            int col = i/2 + 1;
            if(left[col] != -1 || right[col] != -1){
                valid = false;
                break;
            }
            st.push(col);
        }
    }
    
    while(!st.empty()) {
        right[st.top()] = 2*N;
        st.pop();
    }
    
    if(!valid){
        cout << "No";
        return 0;
    }
    
    for(int i=1;i<=2*N;i++){
        if(left[i] != -1){
            ans.push_back(left[i]);
        }
        else{
            for(int j=1;j<=N;j++){
                if(right[j] == i){
                    ans.push_back(j);
                    break;
                }
            }
        }
    }
    
    cout << "Yes\n";
    for(int i=0;i<(2*N);i++){
        cout << ans[i];
        if(i != 2*N-1) cout << " ";
    }
}