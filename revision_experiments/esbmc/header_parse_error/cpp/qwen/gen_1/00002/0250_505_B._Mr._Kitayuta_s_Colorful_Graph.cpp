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

const int N = 105;

vector<int> adj[N];
vector<int> colors[N][N];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        colors[a][b].push_back(c);
        colors[b][a].push_back(c);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int q;
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        set<int> color_set;
        queue<int> q;
        vector<bool> visited(n+1, false);
        q.push(u);
        visited[u] = true;
        while(!q.empty()){
            int current = q.front();
            q.pop();
            for(int next : adj[current]){
                for(int color : colors[current][next]){
                    color_set.insert(color);
                }
                if(!visited[next]){
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        set<int> result_colors;
        for(int color : color_set){
            queue<int> q;
            vector<bool> visited(n+1, false);
            q.push(u);
            visited[u] = true;
            bool can_reach = false;
            while(!q.empty()){
                int current = q.front();
                q.pop();
                if(current == v){
                    can_reach = true;
                    break;
                }
                for(int next : adj[current]){
                    if(find(colors[current][next].begin(), colors[current][next].end(), color) != colors[current][next].end()){
                        if(!visited[next]){
                            visited[next] = true;
                            q.push(next);
                        }
                    }
                }
            }
            if(can_reach){
                result_colors.insert(color);
            }
        }
        cout << result_colors.size() << "\n";
    }
}