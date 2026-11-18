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
    vector<long long> a(n);
    for(auto &x : a) cin >> x;
    int k;
    cin >> k;
    vector<long long> b(k);
    for(auto &x : b) cin >> x;
    if(n==k){
        cout << "YES";
        return 0;
    }
    vector<pair<long long, int>> res;
    deque<int> q;
    for(int i=0;i<n;i++) q.push_back(i);
    int ptr = 0;
    while(q.size()>k){
        bool found = false;
        for(int i=0;i<q.size();i++){
            if(ptr==k) break;
            if(a[q[i]]==b[ptr]){
                if(i>0 && a[q[i-1]]<a[q[i]]){
                    res.push_back({q[i-1]+1, 'L'});
                    a[q[i]]+=a[q[i-1]];
                    q.erase(q.begin()+i-1);
                    i--;
                    found = true;
                }
                else if(i<q.size()-1 && a[q[i+1]]<a[q[i]]){
                    res.push_back({q[i]+1, 'R'});
                    a[q[i]]+=a[q[i+1]];
                    q.erase(q.begin()+i+1);
                    found = true;
                }
            }
        }
        if(!found){
            cout << "NO";
            return 0;
        }
        ptr++;
    }
    cout << "YES\n";
    for(auto [x, c] : res){
        cout << x << " " << c << "\n";
    }
}