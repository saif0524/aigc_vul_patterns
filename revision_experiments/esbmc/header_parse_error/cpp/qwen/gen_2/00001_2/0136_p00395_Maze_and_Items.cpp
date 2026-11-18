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

const int MAXN = 1005;
const int MAXITEM = 1024;
const int INF = 1e9;

int w, h;
char grid[MAXN][MAXN];
int startx, starty, endx, endy;
int item_mask;
int scores[10][10];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dp[MAXN][MAXN][MAXITEM];
bool visited[MAXN][MAXN][MAXITEM];

struct State {
    int x, y, mask, dist, score;
    bool operator<(const State& other) const {
        if (dist == other.dist) return score < other.score;
        return dist > other.dist;
    }
};

bool isValid(int x, int y, int mask) {
    if (x < 0 || x >= h || y < 0 || y >= w || grid[x][y] == '#') return false;
    if (isdigit(grid[x][y])) return true;
    if (islower(grid[x][y])) {
        int item = grid[x][y] - 'a';
        return (mask & (1 << item)) != 0;
    }
    if (isupper(grid[x][y])) {
        int item = grid[x][y] - 'A';
        return (mask & (1 << item)) == 0;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> w >> h;
    for(int i = 0; i < h; i++){
        cin >> grid[i];
        for(int j = 0; j < w; j++){
            if(grid[i][j] == 'S') startx = i, starty = j;
            if(grid[i][j] == 'T') endx = i, endy = j;
            if(isdigit(grid[i][j])) item_mask |= (1 << (grid[i][j] - '0'));
        }
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> scores[i][j];
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    memset(visited, 0, sizeof(visited));
    priority_queue<State> pq;
    pq.push({startx, starty, 0, 0, 0});
    dp[startx][starty][0] = 0;
    while(!pq.empty()){
        State u = pq.top();
        pq.pop();
        if(visited[u.x][u.y][u.mask]) continue;
        visited[u.x][u.y][u.mask] = true;
        if(u.mask == item_mask && u.x == endx && u.y == endy){
            cout << u.dist << " " << u.score;
            return 0;
        }
        for(int k = 0; k < 4; k++){
            int nx = u.x + dx[k];
            int ny = u.y + dy[k];
            int nmask = u.mask;
            int nscore = u.score;
            int ndist = u.dist + 1;
            if(isValid(nx, ny, nmask)){
                if(isdigit(grid[nx][ny])){
                    int item = grid[nx][ny] - '0';
                    if((nmask & (1 << item)) == 0){
                        nmask |= (1 << item);
                        int last_item = nmask == (1 << item) ? 0 : __lg(nmask & ~(1 << item));
                        nscore += scores[last_item][item];
                    }
                }
                if(dp[nx][ny][nmask] > ndist || (dp[nx][ny][nmask] == ndist && nscore > dp[nx][ny][nmask].second)){
                    dp[nx][ny][nmask] = {ndist, nscore};
                    pq.push({nx, ny, nmask, ndist, nscore});
                }
            }
        }
    }
    cout << -1;
}