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
    int n, q;
    cin >> n >> q;
    vector<vector<int>> servers(n, vector<int>(1000001));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i=0;i<n;i++){
        pq.push({0, i+1});
    }
    while(q--){
        int ti, ki, di;
        cin >> ti >> ki >> di;
        while(!pq.empty() && pq.top().first <= ti){
            int freeTime = pq.top().first;
            int id = pq.top().second;
            pq.pop();
            pq.push({freeTime, id});
        }
        vector<int> selected;
        while(!pq.empty() && ki > 0){
            int freeTime = pq.top().first;
            int id = pq.top().second;
            pq.pop();
            if(freeTime <= ti){
                selected.push_back(id);
                ki--;
            } else {
                pq.push({freeTime, id});
                break;
            }
        }
        if(selected.size() == (unsigned)ki){
            int sum = 0;
            for(auto id : selected){
                sum += id;
                pq.push({ti+di, id});
            }
            cout << sum << "\n";
        } else {
            for(auto id : selected){
                pq.push({0, id});
            }
            cout << "-1\n";
        }
    }
}