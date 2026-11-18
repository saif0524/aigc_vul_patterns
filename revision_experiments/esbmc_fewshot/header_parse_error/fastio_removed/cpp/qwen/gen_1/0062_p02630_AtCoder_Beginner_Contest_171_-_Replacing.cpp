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
    
    int N;
    cin >> N;
    vector<long long> A(N);
    map<long long, long long> freq;
    
    for(int i=0;i<N;i++){
        cin >> A[i];
        freq[A[i]]++;
    }
    
    int Q;
    cin >> Q;
    vector<pair<long long, long long>> queries(Q);
    
    for(int i=0;i<Q;i++){
        cin >> queries[i].first >> queries[i].second;
    }
    
    for(int i=0;i<Q;i++){
        long long B = queries[i].first;
        long long C = queries[i].second;
        
        if(freq[B] > 0){
            long long total_to_add = freq[B] * (C - B);
            for(auto &it : freq){
                if(it.first == B){
                    it.second = 0;
                }
                if(it.first == C){
                    it.second += freq[B];
                }
            }
            freq[C] += freq[B];
            freq[B] = 0;
            
            long long current_sum = 0;
            for(auto &it : freq){
                current_sum += it.first * it.second;
            }
            cout << current_sum << "\n";
        }
        else{
            long long current_sum = 0;
            for(auto &it : freq){
                current_sum += it.first * it.second;
            }
            cout << current_sum << "\n";
        }
    }
    
    return 0;
}