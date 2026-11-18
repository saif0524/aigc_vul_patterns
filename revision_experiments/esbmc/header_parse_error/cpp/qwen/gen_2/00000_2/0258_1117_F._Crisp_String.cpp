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
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    vector<vector<int>> A(p, vector<int>(p));
    for(int i = 0; i < p; ++i){
        for(int j = 0; j < p; ++j){
            cin >> A[i][j];
        }
    }
    vector<vector<bool>> dp(p, vector<bool>(p));
    vector<int> comp_id(p, -1);
    int comp_cnt = 0;
    for(int i = 0; i < p; ++i){
        if(comp_id[i] == -1){
            queue<int> q;
            q.push(i);
            comp_id[i] = comp_cnt;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(int v = 0; v < p; ++v){
                    if(A[u][v] && comp_id[v] == -1){
                        comp_id[v] = comp_cnt;
                        q.push(v);
                    }
                }
            }
            comp_cnt++;
        }
    }
    vector<int> comp_size(comp_cnt, 0);
    for(char c : s){
        comp_size[comp_id[c-'a']]++;
    }
    vector<bool> exists(comp_cnt, false);
    for(int i = 0; i < comp_cnt; ++i){
        exists[i] = (comp_size[i] > 0);
    }
    vector<int> G[comp_cnt];
    for(int i = 0; i < comp_cnt; ++i){
        for(int j = 0; j < comp_cnt; ++j){
            if(i != j){
                bool edge = false;
                for(int x = 0; x < p; ++x){
                    for(int y = 0; y < p; ++y){
                        if(comp_id[x] == i && comp_id[y] == j && A[x][y]){
                            edge = true;
                            break;
                        }
                    }
                    if(edge) break;
                }
                if(edge) G[i].push_back(j);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < comp_cnt; ++i){
        if(exists[i]){
            vector<bool> visited(comp_cnt, false);
            queue<int> q;
            q.push(i);
            visited[i] = true;
            int sum = 0;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                sum += comp_size[u];
                for(int v : G[u]){
                    if(!visited[v]){
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            ans += (sum > 0 ? 1 : 0);
        }
    }
    cout << max(0, ans-1) << "\n";
}