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
    int n, t;
    long long k;
    cin >> n >> t >> k;
    vector<long long> a(n), b(n), c(n);
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    int low = 0, high = t*n;
    while(low < high){
        int mid = (low + high) / 2;
        vector<long long> people = a;
        bool valid = true;
        vector<long long> trains(t, 0);
        for(int i=0;i<mid;i++) trains[i%t]++;
        for(int hour=0;hour<t && valid;hour++){
            long long capacity = 0;
            for(int i=0;i<t;i++) capacity += trains[i]*k;
            for(int station=0;station<n;station++){
                if(people[station] > capacity) valid = false;
                else{
                    long long take = min(capacity, people[station]);
                    capacity -= take;
                    people[station] -= take;
                    if(station < n-1) people[station+1] += people[station];
                    people[station] = 0;
                }
            }
            for(int station=0;station<n;station++){
                people[station] += b[station];
                if(people[station] > c[station]) valid = false;
            }
        }
        if(valid) high = mid;
        else low = mid + 1;
    }
    cout << low;
}