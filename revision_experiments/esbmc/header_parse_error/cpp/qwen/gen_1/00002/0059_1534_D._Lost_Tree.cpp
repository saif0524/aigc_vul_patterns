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
    int n;
    cin >> n;
    vector<vector<int>> dist(n, vector<int>(n));
    vector<pair<int,int>> edges;
    auto ask = [&](int node){
        cout << "? " << node + 1 << endl;
        cout.flush();
        for(int i=0;i<n;i++) cin >> dist[node][i];
    };
    auto find_diameter = [&](auto&& find_diameter, int node, int parent) -> pair<int,int> {
        int max1 = -1, max2 = -1;
        int node1 = -1;
        for(int i=0;i<n;i++){
            if(i == parent) continue;
            if(dist[node][i] > max1){
                max2 = max1;
                max1 = dist[node][i];
                node1 = i;
            }else if(dist[node][i] > max2){
                max2 = dist[node][i];
            }
        }
        pair<int,int> res = {max1, node1};
        for(int i=0;i<n;i++){
            if(i == parent) continue;
            auto [d, nd] = find_diameter(find_diameter, i, node);
            if(d + dist[node][i] > max1 + max2){
                res = {d + dist[node][i], -1};
            }
        }
        return res;
    };
    ask(0);
    auto [diam, start] = find_diameter(find_diameter, 0, -1);
    ask(start);
    tie(diam, start) = find_diameter(find_diameter, start, -1);
    int s = start;
    vector<int> path;
    while(1){
        path.push_back(s);
        int nxt = -1;
        for(int i=0;i<n;i++){
            if(dist[s][i] == dist[start][s] - 1){
                nxt = i;
                break;
            }
        }
        if(nxt == -1) break;
        s = nxt;
    }
    for(int i=0;i+1<(int)path.size();i++){
        edges.emplace_back(path[i]+1, path[i+1]+1);
    }
    int have = (int)path.size() - 1;
    set<int> used(path.begin(), path.end());
    for(int i=0;i<n && have < n - 1;i++){
        if(used.count(i)) continue;
        int best = -1;
        for(int j=0;j<(int)path.size();j++){
            if(best == -1 || dist[path[j]][i] < dist[path[best]][i]){
                best = j;
            }
        }
        edges.emplace_back(path[best]+1, i+1);
        have++;
    }
    cout << "!" << endl;
    for(auto [u,v]: edges){
        cout << u << " " << v << endl;
    }
    cout.flush();
}