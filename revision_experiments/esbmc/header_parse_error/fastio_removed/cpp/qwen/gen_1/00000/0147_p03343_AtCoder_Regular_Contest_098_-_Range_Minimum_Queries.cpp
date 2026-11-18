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
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> A(N);
    for(auto &a : A) cin >> a;
    multiset<int> ms;
    for(int i=0;i<K;i++) ms.insert(A[i]);
    vector<int> candidates;
    candidates.push_back(*ms.begin());
    for(int i=K;i<N;i++){
        ms.insert(A[i]);
        ms.erase(ms.find(A[i-K]));
        candidates.push_back(*ms.begin());
    }
    sort(candidates.begin(), candidates.end());
    int ans = INT_MAX;
    for(int i=0;i<=Q-1;i++){
        ans = min(ans, candidates[i+K-1-Q+1] - candidates[i]);
    }
    cout << ans;
}