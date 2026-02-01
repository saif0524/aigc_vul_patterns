#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct State {
    int x, y, mask, dist;
    State(int _x, int _y, int _mask, int _dist) : x(_x), y(_y), mask(_mask), dist(_dist) {}
};

int main(){
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> grid(H);
    int start_x = -1, start_y = -1, end_x = -1, end_y = -1;
    vector<pair<int, int>> apples;
    for(int i=0; i<H; ++i){
        cin >> grid[i];
        for(int j=0; j<W; ++j){
            if(grid[i][j] == 's'){
                start_x = i;
                start_y = j;
            }
            if(grid[i][j] == 'e'){
                end_x = i;
                end_y = j;
            }
            if(grid[i][j] == 'a'){
                apples.push_back({i, j});
            }
        }
    }

    int total_apples = apples.size();
    int target_mask = (1 << total_apples) - 1;
    vector<vector<vector<bool>>> visited(H, vector<vector<bool>>(W, vector<bool>(1 << total_apples, false)));
    queue<State> q;
    q.emplace(start_x, start_y, 0, 0);
    visited[start_x][start_y][0] = true;

    while(!q.empty()){
        auto [x, y, mask, dist] = q.front();
        q.pop();

        if(x == end_x && y == end_y && mask == target_mask){
            cout << dist << "\n";
            return 0;
        }

        for(int i=0; i<4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= H || ny < 0 || ny >= W || grid[nx][ny] == '#'){
                continue;
            }
            int new_mask = mask;
            for(int j=0; j<total_apples; ++j){
                if(apples[j].first == nx && apples[j].second == ny && !(mask & (1 << j))){
                    new_mask |= (1 << j);
                    break;
                }
            }
            if(!visited[nx][ny][new_mask]){
                visited[nx][ny][new_mask] = true;
                q.emplace(nx, ny, new_mask, dist + 1);
            }
        }
    }

    cout << "-1\n";
}