#include <bits/stdc++.h>
using namespace std;

const int MAXM = 55, MAXN = 55;

int m, n;
char grid[MAXM][MAXN];
int block[MAXM][MAXN];
int num_blocks = 0;

pair<int, int> block_bounds[1000][4];

void find_blocks() {
    bool visited[MAXM][MAXN] = {0};
    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] != '0' && !visited[i][j]) {
                int c = grid[i][j];
                int left = 1e9, right = -1, top = 1e9, bottom = -1;
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;

                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    left = min(left, y);
                    right = max(right, y);
                    top = min(top, x);
                    bottom = max(bottom, x);

                    for (int k = 0; k < 4; ++k) {
                        int xx = x + dx[k], yy = y + dy[k];
                        if (xx >= 0 && xx < m && yy >= 0 && yy < n && grid[xx][yy] == c && !visited[xx][yy]) {
                            visited[xx][yy] = true;
                            q.push({xx, yy});
                        }
                    }
                }

                block_bounds[num_blocks][0] = {top, left};
                block_bounds[num_blocks][1] = {top, right};
                block_bounds[num_blocks][2] = {bottom, left};
                block_bounds[num_blocks][3] = {bottom, right};
                for (int x = top; x <= bottom; ++x) {
                    for (int y = left; y <= right; ++y) {
                        block[x][y] = num_blocks;
                    }
                }
                num_blocks++;
            }
        }
    }
}

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    for(int i=0;i<m;i++) cin >> grid[i];

    find_blocks();

    int cur_block = block[0][0];
    int cur_dir = 1; // right
    int cur_cp = 0; // left

    auto get_edge_pixel = [&](int dir) -> pair<int, int> {
        auto [tx, ty] = block_bounds[cur_block][dir];
        auto [nx, ny] = block_bounds[cur_block][(dir + 2) % 4];
        int cx = (tx + nx) / 2;
        int cy = (ty + ny) / 2;
        int side_dir = (dir % 2 == 0) ? 2 : 3;
        int side_nx = cx + dx[side_dir];
        int side_ny = cy + dy[side_dir];
        if (grid[side_nx][side_ny] == '0' || side_nx < 0 || side_nx >= m || side_ny < 0 || side_ny >= n) {
            cur_cp = (cur_cp ? 0 : 1);
        } else {
            cx = side_nx;
            cy = side_ny;
        }
        return {cx, cy};
    };

    for(int step=0;step<n;step++){
        auto [x, y] = get_edge_pixel(cur_dir);
        int nx = x + dx[cur_dir];
        int ny = y + dy[cur_dir];
        if(nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == '0'){
            if(cur_cp == 0){
                cur_cp = 1;
            }
            else{
                cur_dir = (cur_dir + 1) % 4;
                cur_cp = 0;
            }
        }
        else{
            cur_block = block[nx][ny];
        }
    }

    cout << grid[block_bounds[cur_block][0].first][block_bounds[cur_block][0].second] << "\n";
}