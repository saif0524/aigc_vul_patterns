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
    int N, M;
    cin >> N >> M;
    vector<int> L(N), R(N);
    for(int i=0;i<N;i++) cin >> L[i] >> R[i];
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());
    int ans = 0, i = 0, j = 0, seated = 0;
    while(i < N){
        if(L[i] <= R[j]){
            seated++;
            i++;
        }
        else{
            seated--;
            j++;
        }
        ans = max(ans, seated - (j - i + 1));
    }
    cout << max(ans, seated - (N - M));
}