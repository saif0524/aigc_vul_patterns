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
    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        vector<vector<int>> minions(n);
        for(int i=0;i<n;i++){
            int a, b;
            cin >> a >> b;
            minions[i] = {a, b, i+1};
        }
        sort(minions.begin(), minions.end(), [&](auto &x, auto &y){
            return (x[0] + x[1]*(k-1)) > (y[0] + y[1]*(k-1));
        });
        priority_queue<int, vector<int>, greater<int>> current;
        vector<int> actions;
        for(int i=0;i<k;i++){
            actions.push_back(minions[i][2]);
            current.push(minions[i][0]);
            for(int j=0;j<i;j++){
                minions[j][0] += minions[i][1];
            }
        }
        for(int i=k;i<n;i++){
            int new_minion_power = minions[i][0] + minions[i][1]*(k-1);
            int current_min = current.top();
            if(new_minion_power > current_min){
                actions.push_back(-current.top());
                current.pop();
                actions.push_back(minions[i][2]);
                current.push(minions[i][0]);
                for(int j=0;j<i;j++){
                    minions[j][0] += minions[i][1];
                }
            }
        }
        cout << actions.size() << "\n";
        for(auto &x: actions){
            cout << x << " ";
        }
        cout << "\n";
    }
}