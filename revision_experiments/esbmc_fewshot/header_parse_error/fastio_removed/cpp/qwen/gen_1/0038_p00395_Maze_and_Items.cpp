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

const int MAXN =1005;
const int MAXITEMS = 10;
const int INF = 1e9;

int W, H;
char grid[MAXN][MAXN];
int sx, sy, tx, ty;
int itemPos[MAXITEMS][2];
int itemMap[11];
bool hasItem[1 << MAXITEMS];
int scoreTable[MAXITEMS][MAXITEMS];
int dist[MAXN][MAXN][1 << MAXITEMS];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool isValid(int x, int y) {
    return x >= 0 && x < H && y >= 0 && y < W;
}

int bfs() {
    queue<tuple<int, int, int>> q;
    memset(dist, -1, sizeof(dist));
    q.emplace(sx, sy, 0);
    dist[sx][sy]= 0;
    int maxScore = 0;

    while (!q.empty()) {
        auto [x, y, mask] = q.front();
        q.pop();

        if (x == tx && y == ty) {
            if (__builtin_popcount(mask) == 10) {
                return dist[x][y][mask];
            }
            continue;
        }

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (!isValid(nx, ny) || grid[nx][ny] == '#') continue;

            int newMask = mask;
            int scoreGain = 0;

            if (isdigit(grid[nx][ny])) {
                int item = grid[nx][ny] - '0';
                if (!(newMask & (1 << item))) {
                    newMask |= (1 << item);
                    scoreGain = scoreTable[__builtin_ctz(mask)][item];
                }
            } else if (isupper(grid[nx][ny])) {
                int item = itemMap[grid[nx][ny] - 'A'];
                if (newMask & (1 << item)) continue;
            } else if (islower(grid[nx][ny])) {
                int item = itemMap[grid[nx][ny] - 'a'];
                if (!(newMask & (1 << item))) continue;
            }

            if (dist[nx][ny][newMask] == -1) {
                dist[nx][ny][newMask] = dist[x][y][mask] + 1;
                q.emplace(nx, ny, newMask);
            }
        }
    }

    return -1;
}

int main(){
    ((void)0);
    ((void)0);

    cin >> W >> H;
    for(int i=0;i<H;i++){
        cin >> grid[i];
        for(int j=0;j<W;j++){
            if(grid[i][j]=='S'){
                sx=i;
                sy=j;
            }
            else if(grid[i][j]=='T'){
                tx=i;
                ty=j;
            }
            else if(isdigit(grid[i][j])){
                int item = grid[i][j]-'0';
                itemPos[item][0]=i;
                itemPos[item][1]=j;
            }
            else if(isupper(grid[i][j])){
                itemMap[grid[i][j]-'A']=grid[i][j]-'0';
            }
            else if(islower(grid[i][j])){
                itemMap[grid[i][j]-'a']=grid[i][j]-'0';
            }
        }
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin >> scoreTable[i][j];
        }
    }

    int result = bfs();
    cout << result << "\n";

    return 0;
}