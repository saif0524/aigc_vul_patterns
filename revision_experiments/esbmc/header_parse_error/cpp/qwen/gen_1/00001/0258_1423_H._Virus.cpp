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
    int n, q, k;
    cin >> n >> q >> k;
    vector<unordered_set<int>> contacts(n+1);
    vector<vector<pair<int, int>>> queries(k);
    for(int day = 0; day < q; ++day){
        int t;
        cin >> t;
        if(t == 1){
            int x, y;
            cin >> x >> y;
            queries[day].emplace_back(x, y);
            queries[day].emplace_back(y, x);
        }
        else if(t == 2){
            int z;
            cin >> z;
            int count = 0;
            unordered_set<int> seen;
            queue<int> q;
            q.push(z);
            seen.insert(z);
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(const int& neighbor : contacts[node]){
                    if(seen.find(neighbor) == seen.end()){
                        seen.insert(neighbor);
                        q.push(neighbor);
                    }
                }
                count++;
            }
            cout << count << "\n";
        }
        else{
            if(!queries.empty()){
                int day_idx = (day - 1) % k;
                for(auto& [x, y] : queries[day_idx]){
                    contacts[x].insert(y);
                }
            }
        }
    }
}