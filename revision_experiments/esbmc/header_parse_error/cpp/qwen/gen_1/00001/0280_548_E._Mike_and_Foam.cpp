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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    vector<vector<int>> divisors(500001);
    for(int i=1;i<=500000;i++){
        for(int j=i;j<=500000;j+=i){
            divisors[j].push_back(i);
        }
    }
    vector<int> freq(500001);
    vector<long long> counts(500001);
    long long current_score = 0;
    for(int i=0;i<q;i++){
        int x;
        cin >> x;
        x--;
        if(freq[a[x]]){
            for(int d: divisors[a[x]]){
                current_score -= counts[d];
                counts[d] -= freq[a[x]];
            }
        }
        freq[a[x]] ^= 1;
        if(freq[a[x]]){
            for(int d: divisors[a[x]]){
                counts[d] += freq[a[x]];
                current_score += counts[d];
            }
        }
        cout << current_score / 2 << "\n";
    }
}