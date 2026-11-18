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

typedef pair<int, int> pii;

int main(){
    int n, k;
    cin >> n >> k;
    vector<pii> a, b, ab;
    for(int i=0;i<n;i++){
        int t, ai, bi;
        cin >> t >> ai >> bi;
        if(ai && bi) ab.push_back({t, i});
        else if(ai) a.push_back({t, i});
        else if(bi) b.push_back({t, i});
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(ab.begin(), ab.end());
    if(ab.size() >= k){
        long long sum = 0;
        for(int i=0;i<k;i++) sum += ab[i].first;
        long long best = sum;
        int aa=0, bb=0;
        int i = 0, j = 0;
        while(i<a.size()&&j<b.size()&&aa+(int)ab.size()<k&&(bb+(int)ab.size()<k)){
            if(a[i].first + b[j].first < ab[aa+(int)ab.size()].first){
                sum += a[i].first + b[j].first - ab[aa+(int)ab.size()].first;
                aa++, bb++;
                i++, j++;
            }
            else{
                long long mn = min(aa, bb);
                sum += (i+j-mn-mn)*(ab[aa+mn].first - ab[aa+mn-1].first);
                aa = bb = mn + k;
            }
            best = min(best, sum);
        }
        cout << best;
        return 0;
    }
    else if(a.size()+b.size()+(int)ab.size() < 2*k){
        cout << -1;
        return 0;
    }
    else{
        long long sum = 0;
        for(int i=0;i<k-(int)ab.size();i++) sum += a[i].first + b[i].first;
        for(int i=0;i<ab.size();i++) sum += ab[i].first;
        cout << sum;
    }
}