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
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) { cin >> x; }
    sort(a.begin(), a.end());

    double total = 0, favorable = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == j) continue;
            for(int k=0;k<n;k++){
                if(k == i || k == j) continue;
                int andy_sum = a[i] + a[j];
                int jerry_sum = a[k];
                for(int l=0;l<n;l++){
                    if(l == i || l == j || l == k) continue;
                    for(int m=0;m<n;m++){
                        if(m == i || m == j || m == k || m == l) continue;
                        andy_sum += a[l] + a[m];
                        jerry_sum += a[n-1-(l<m?l:m)] + a[n-2-(l<m?l:m)-(l>m?l:m)];
                        if(jerry_sum > andy_sum) favorable++;
                        andy_sum -= a[l] + a[m];
                        jerry_sum -= a[n-1-(l<m?l:m)] + a[n-2-(l<m?l:m)-(l>m?l:m)];
                    }
                }
                total++;
            }
        }
    }

    cout << fixed << setprecision(10) << (favorable / total) << endl;
}