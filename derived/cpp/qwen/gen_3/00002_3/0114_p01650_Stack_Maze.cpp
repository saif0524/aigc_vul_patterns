#include <bits/stdc++.h>
using namespace std;

const int MAX_H = 55;
const int MAX_W = 55;

int H, W;
char grid[MAX_H][MAX_W];
int dx[] = {0, 1};
int dy[] = {1, 0};
vector<pair<int, int>> jewel_positions;
unordered_map<int, int> jewel_count;
bool visited[MAX_H][MAX_W][1 << 10];
int result;

void dfs(int x, int y, int mask) {
    if (x == W - 1 && y == H - 1) {
        int cnt = __builtin_popcount(mask);
        result = max(result, cnt);
        return;
    }
    int id = grid[y][x] - 'a';
    if (id >= 0 && id < 26) {
        if ((mask & (1 << id)) == 0) {
            int new_mask = mask | (1 << id);
            if (!visited[y][x][new_mask]) {
                visited[y][x][new_mask] = true;
                dfs(x, y, new_mask);
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < W && ny >= 0 && ny < H && grid[ny][nx] != '#') {
            int id = grid[ny][nx] - 'A';
            if (id >= 0 && id < 26) {
                if (mask & (1 << id)) {
                    int new_mask = mask & (~(1 << id));
                    if (!visited[ny][nx][new_mask]) {
                        visited[ny][nx][new_mask] = true;
                        dfs(nx, ny, new_mask);
                    }
                }
            } else {
                if (!visited[ny][nx][mask]) {
                    visited[ny][nx][mask] = true;
                    dfs(nx, ny, mask);
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(true){
        cin >> H >> W;
        if(H == 0 && W == 0) break;
        result = -1;
        jewel_positions.clear();
        jewel_count.clear();
        for(int i = 0; i < H; i++) cin >> grid[i];
        memset(visited, false, sizeof(visited));
        dfs(0, 0, 0);
        cout << result << "\n";
    }
}