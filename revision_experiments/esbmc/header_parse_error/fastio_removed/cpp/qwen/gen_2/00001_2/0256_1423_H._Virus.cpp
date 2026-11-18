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
    int n, q, k;
    cin >> n >> q >> k;
    vector<set<int>> days[k];
    vector<set<int>> contacts(n+1);
    int day = 0;
    while(q--){
        int t;
        cin >> t;
        if(t==1){
            int x, y;
            cin >> x >> y;
            contacts[x].insert(x);
            contacts[y].insert(y);
            contacts[x].insert(contacts[y].begin(), contacts[y].end());
            contacts[y].insert(contacts[x].begin(), contacts[x].end());
            days[day%k][x].insert(y);
            days[day%k][y].insert(x);
        }else if(t==2){
            int i;
            cin >> i;
            cout << contacts[i].size() << "\n";
        }else{
            for(auto& p: days[day%k]){
                int x = p.first;
                for(auto& y: p.second){
                    contacts[x].erase(y);
                    contacts[y].erase(x);
                }
            }
            fill(days[day%k].begin(), days[day%k].end(), set<int>());
            day++;
        }
    }
}