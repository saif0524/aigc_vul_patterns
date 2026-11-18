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
        vector<pair<int, int>> minions(n);
        for(int i=0;i<n;i++){
            cin >> minions[i].first >> minions[i].second;
        }
        priority_queue<int> pq;
        vector<int> ans;
        int cnt = 0;
        int power = 0;
        sort(minions.begin(), minions.end(), [&](const pair<int,int>& a, const pair<int,int>& b){
            return a.first + cnt * a.second > b.first + cnt * b.second;
        });
        for(auto& [a, b] : minions){
            if(cnt < k){
                ans.push_back(a+1);
                pq.push(-a);
                power += a;
                cnt++;
                power += cnt * b;
            }
            else{
                if(-pq.top() < a){
                    int old_minion = -pq.top();
                    pq.pop();
                    ans.push_back(-(old_minion+1));
                    cnt--;
                    power -= old_minion;
                    power -= cnt * b;
                    
                    ans.push_back(a+1);
                    pq.push(-a);
                    power += a;
                    cnt++;
                    power += cnt * b;
                }
                else{
                    power += cnt * b;
                }
            }
        }
        cout << ans.size() << "\n";
        for(auto x : ans){
            cout << x << " ";
        }
        cout << "\n";
    }
}