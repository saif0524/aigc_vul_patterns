#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct State {
    int x, y, time, dir;
    State(int x, int y, int time, int dir) : x(x), y(y), time(time), dir(dir) {}
};

bool isValid(int x, int y, int R, int C, vector<string> &grid) {
    return x >= 0 && x < R && y >= 0 && y < C && grid[x][y] != '#';
}

void paint(vector<string> &grid, int x, int y, int dir) {
    for (int d = 1; d <= 3; d++) {
        int nx = x + dx[dir] * d;
        int ny = y + dy[dir] * d;
        if (!isValid(nx, ny, grid.size(), grid[0].size(), grid)) break;
        if (grid[nx][ny] == 'x') break;
        if (grid[nx][ny] == '.') grid[nx][ny] = 'o';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int R, C;
    cin >> R >> C;
    vector<string> grid(R);
    for(auto &row: grid) cin >> row;
    int startX, startY;
    int goalX, goalY;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(grid[i][j] == 'S'){
                startX = i, startY = j;
                grid[i][j] = '.';
            }
            else if(grid[i][j] == 'G'){
                goalX = i, goalY = j;
                grid[i][j] = '.';
            }
        }
    }
    priority_queue<tuple<int, int, int, int, int>, vector<tuple<int, int, int, int, int>>, greater<tuple<int, int, int, int, int>>> pq;
    pq.emplace(0, startX, startY, 0, 0);
    unordered_set<string> visited;
    string startKey = to_string(startX) + "," + to_string(startY) + "," + to_string(0);
    visited.insert(startKey);
    while(!pq.empty()){
        auto [time, x, y, prevDir, paintTime] = pq.top();
        pq.pop();
        if(x == goalX && y == goalY)return cout << time, 0;
        for(int k=0;k<4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(isValid(nx, ny, R, C, grid)){
                string key = to_string(nx) + "," + to_string(ny) + "," + to_string(time);
                if(visited.find(key) == visited.end()){
                    visited.insert(key);
                    int cost = grid[nx][ny] == '.' ? 2 : 1;
                    if(paintTime == 2){
                        pq.emplace(time + cost, nx, ny, k, 0);
                    }
                    else{
                        pq.emplace(time + cost, nx, ny, k, paintTime + 1);
                    }
                }
            }
        }
        if(paintTime < 2){
            vector<string> tempGrid = grid;
            paint(tempGrid, x, y, prevDir);
            string key = to_string(x) + "," + to_string(y) + "," + to_string(time + 2);
            if(visited.find(key) == visited.end()){
                visited.insert(key);
                pq.emplace(time + 2, x, y, prevDir, paintTime + 1);
            }
        }
    }
    return 0;
}