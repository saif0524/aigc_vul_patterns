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
    int n, k;
    cin >> n >> k;
    vector<int> deg(n+1, 0);
    vector<pair<int, int>> edges(k);
    for(int i=0;i<k;i++){
        cin >> edges[i].first >> edges[i].second;
        deg[edges[i].first]++;
        deg[edges[i].second]++;
    }
    set<int> s;
    for(int i=1;i<=n;i++){
        s.insert(deg[i]);
    }
    int cnt=0;
    vector<int> keep;
    for(int i=1;i<=n;i++){
        if(s.count(deg[i])){
            cnt++;
            keep.push_back(i);
            s.erase(deg[i]);
        }
    }
    cout << cnt << "\n";
    for(int i=0;i<cnt;i++){
        cout << keep[i] << " ";
    }
    cout << "\n";
    vector<int> ans(k, 0);
    set<int> used;
    for(int i=0;i<k;i++){
        if(!used.count(edges[i].first) && !used.count(edges[i].second)){
            if(deg[edges[i].first] > deg[edges[i].second]){
                ans[i] = 1;
                used.insert(edges[i].second);
            }
            else if(deg[edges[i].first] < deg[edges[i].second]){
                ans[i] = 2;
                used.insert(edges[i].first);
            }
            else{
                ans[i] = 1;
                used.insert(edges[i].second);
            }
        }
    }
    for(int i=0;i<k;i++){
        cout << edges[i].first << " " << edges[i].second << " " << ans[i] << "\n";
    }
}