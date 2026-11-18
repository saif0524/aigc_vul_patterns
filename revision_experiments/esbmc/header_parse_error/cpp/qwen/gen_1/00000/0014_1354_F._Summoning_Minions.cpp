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
    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> minions(n);
        for(int i=0;i<n;i++){
            cin >> minions[i].first >> minions[i].second;
        }
        vector<int> actions;
        priority_queue<int> active;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> inactive;
        for(int i=0;i<n;i++){
            inactive.push({minions[i].first, i+1});
        }
        while(!inactive.empty() || !active.empty()){
            if(active.size() < k && !inactive.empty()){
                auto [power, idx] = inactive.top();
                inactive.pop();
                actions.push_back(idx);
                active.push(power);
            }
            else if(active.size() > k){
                int smallest = active.top();
                active.pop();
                for(auto &[p, idx] : inactive){
                    if(p == smallest){
                        actions.push_back(-idx);
                        break;
                    }
                }
            }
            else{
                if(active.size() == k){
                    break;
                }
            }
            vector<pair<int, int>> temp;
            while(!inactive.empty()){
                auto [power, idx] = inactive.top();
                inactive.pop();
                power += active.size();
                temp.push_back({power, idx});
            }
            for(auto &p : temp){
                inactive.push({p.first, p.second});
            }
        }
        cout << actions.size() << "\n";
        for(auto a : actions){
            cout << a << " ";
        }
        cout << "\n";
    }
}