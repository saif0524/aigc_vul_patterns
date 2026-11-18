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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> not_adjacent(n+1);
    for(int i=0; i<m; ++i){
        int x, y;
        cin >> x >> y;
        not_adjacent[x].push_back(y);
        not_adjacent[y].push_back(x);
    }
    vector<int> component_size;
    vector<bool> visited(n+1, false);
    for(int i=1; i<=n; ++i){
        if(!visited[i]){
            int size = 0;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                ++size;
                for(int j=1; j<=n; ++j){
                    if(!visited[j]){
                        bool is_adjacent = true;
                        for(int v : not_adjacent[u]){
                            if(v == j){
                                is_adjacent = false;
                                break;
                            }
                        }
                        if(is_adjacent){
                            q.push(j);
                            visited[j] = true;
                        }
                    }
                }
            }
            component_size.push_back(size);
        }
    }
    sort(component_size.begin(), component_size.end());
    cout << component_size.size() << "\n";
    for(int s : component_size){
        cout << s << " ";
    }
    cout << "\n";
    return 0;
}