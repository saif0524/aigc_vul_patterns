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
        int n;
        cin >> n;
        vector<int> a(n);
        for(int &x : a) cin >> x;
        vector<char> res(n, '0');
        for(int k = 1; k <= n; k++){
            bool is_permutation = true;
            vector<int> freq(n+1, 0);
            for(int i = 0; i < k; i++) freq[a[i]]++;
            for(int i = 1; i <= k; i++) if(freq[i] != 1) is_permutation = false;
            if(is_permutation) res[k-1] = '1';
            for(int i = k; i < n; i++){
                freq[a[i-k]]--;
                freq[a[i]]++;
                bool valid = true;
                for(int j = 1; j <= k; j++) if(freq[j] != 1) valid = false;
                if(valid) res[k-1] = '1';
            }
        }
        for(char c : res) cout << c;
        cout << "\n";
    }
    return 0;
}