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
    vector<pair<long long, int>> cards;
    long long total_damage = 0;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        for(int j=0;j<k;j++){
            int c, d;
            cin >> c >> d;
            if(c <= 3){
                total_damage += d;
                cards.push_back({d, c});
            }
        }
    }
    for(int c=1;c<=3;c++){
        long long sum = 0;
        int count = 0;
        priority_queue<int> pq;
        for(auto &[d, cost]: cards){
            if(cost == c){
                sum += d;
                count++;
                pq.push(d);
                if(count > 3){
                    sum -= pq.top();
                    pq.pop();
                    count--;
                }
            }
        }
        total_damage -= sum;
        while(!pq.empty()){
            if((count-1)%9 == 0) total_damage += pq.top();
            count--;
            pq.pop();
        }
    }
    cout << total_damage;
}