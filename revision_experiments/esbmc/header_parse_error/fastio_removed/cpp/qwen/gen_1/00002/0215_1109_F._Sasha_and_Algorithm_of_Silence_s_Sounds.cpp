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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    vector<pair<int, pair<int, int>>> pos(n*m+1);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            pos[grid[i][j]] = {i, j};
        }
    }
    int ans = 0;
    for(int len = 1; len <= n*m; len++){
        set<pair<int, int>> S;
        for(int i = 1; i + len - 1 <= n*m; i++){
            int r = i + len - 1;
            S.insert(pos[i]);
            S.insert(pos[r]);
            if(S.size() != len) continue;
            vector<vector<bool>> visit(n, vector<bool>(m));
            queue<pair<int, int>> q;
            q.push(pos[i]);
            visit[pos[i].first][pos[i].second] = true;
            int cnt = 0;
            while(!q.empty()){
                auto [x, y] = q.front();
                q.pop();
                cnt++;
                for(int dx = -1; dx <= 1; dx++){
                    for(int dy = -1; dy <= 1; dy++){
                        if(abs(dx) + abs(dy) == 1){
                            int nx = x + dx;
                            int ny = y + dy;
                            if(nx >= 0 && nx < n && ny >= 0 && ny < m && S.count({nx, ny}) && !visit[nx][ny]){
                                visit[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
            if(cnt == len){
                ans++;
            }
        }
    }
    cout << ans;
}