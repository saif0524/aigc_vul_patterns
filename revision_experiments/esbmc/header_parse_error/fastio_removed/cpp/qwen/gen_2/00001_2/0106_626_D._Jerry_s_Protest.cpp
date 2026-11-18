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
    sort(a.begin(), a.end());
    if(n < 3){
        cout << "0.0000000000";
        return 0;
    }
    double tot=0, win=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                tot++;
                int andy=a[i] + a[j];
                int jerry=a[k];
                vector<int> left;
                for(int l=0; l<n; l++){
                    if(l!=i && l!=j && l!=k) left.push_back(a[l]);
                }
                for(int x=0; x<3; x++){
                    for(int y=x+1; y<3; y++){
                        if(left[x] + left[y] < andy && jerry > left[3-x-y-1]){
                            win++;
                        }
                    }
                }
            }
        }
    }
    cout << fixed << setprecision(10) << win/tot/6.0;
}