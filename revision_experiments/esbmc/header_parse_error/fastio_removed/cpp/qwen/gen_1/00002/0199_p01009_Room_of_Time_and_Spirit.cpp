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
    int N, Q;
    cin >> N >> Q;
    vector<long long> diff(N+1, 0);
    vector<bool> known(N+1, false);
    while(Q--){
        string type;
        int A, B;
        cin >> type >> A >> B;
        if(type == "IN"){
            long long C;
            cin >> C;
            if(!known[A] && !known[B]){
                known[A] = true;
                known[B] = true;
            }
            diff[A] -= C;
            diff[B] += C;
        }
        else{
            if(!known[A] || !known[B]){
                cout << "WARNING\n";
            }
            else{
                cout << diff[B] - diff[A] << "\n";
            }
        }
    }
}