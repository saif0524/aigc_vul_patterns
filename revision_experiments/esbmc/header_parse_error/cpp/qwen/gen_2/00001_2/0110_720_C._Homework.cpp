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
        int n, m, k;
        cin >> n >> m >> k;
        if(k == 0){
            if(n*m == 1){
                cout << "*\n";
            }
            else if(n == 1){
                for(int i=0;i<m;i++)cout << "*";
                cout << "\n";
            }
            else{
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        if(i==0 && j==0)cout << "*";
                        else cout << ".";
                    }
                    cout << "\n";
                }
            }
        }
        else if(k == 1){
            if(n < 2 || m < 2){
                cout << "-1\n";
            }
            else{
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        if(i == 0 && j == 0)cout << "*";
                        else if(i == 0 && j == 1)cout << "*";
                        else if(i == 1 && j == 0)cout << "*";
                        else cout << ".";
                    }
                    cout << "\n";
                }
            }
        }
        else{
            if(n < 2 || m < 2){
                cout << "-1\n";
            }
            else{
                int need = 0, x = 0, y = 0;
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        if(need == k){
                            cout << '.';
                        }
                        else if(need < k){
                            if((i == x && j == y) || (i == x && j == y + 1) || (i == x + 1 && j == y)){
                                cout << "*";
                                need++;
                            }
                            else cout << ".";
                        }
                        if(j == m - 1){
                            if(x + 1 < n && y + 2 < m){
                                y += 2;
                            }
                            else if(x + 3 < n){
                                x += 2;
                                y = 0;
                            }
                            else{
                                x = 0;
                                y = 0;
                                need = 0;
                            }
                        }
                    }
                    cout << '\n';
                }
            }
        }
        cout << '\n';
    }
}