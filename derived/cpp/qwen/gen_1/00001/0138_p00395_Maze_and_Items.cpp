#include <bits/stdc++.h>
using namespace std;

int W, H;
char grid[1005][1005];
int scores[10][10];
pair<int, int> start, finish;
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
int item_order[1001], item_count = 0;
bool has_item[10];

struct State {
    int i, j, dist, items_mask;
    bool operator<(const State &other) const {
        return dist > other.dist;
    }
};

bool valid(int i, int j, int items_mask) {
    if (i < 0 || i >= H || j < 0 || j >= W) return false;
    if (grid[i][j] == '#') return false;
    if (grid[i][j] >= 'A' && grid[i][j] <= 'J' && (items_mask & (1 << (grid[i][j] - 'A')))) return false;
    if (grid[i][j] >= 'a' && grid[i][j] <= 'j' && !(items_mask & (1 << (grid[i][j] - 'a')))) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> W >> H;
    for(int i=0; i<H; i++) cin >> grid[i];
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(grid[i][j] == '0' + item_count) item_order[item_count++] = i * W + j;
            if(grid[i][j] == 'S') start = {i, j};
            if(grid[i][j] == 'T') finish = {i, j};
        }
    }
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin >> scores[i][j];
        }
    }
    priority_queue<State> pq;
    pq.push({start.first, start.second, 0, 0});
    int vis[H][W][1<<10] = {0};
    vis[start.first][start.second][0] = 1;
    int max_score = -1, min_dist = -1;
    while(!pq.empty()){
        State u = pq.top();
        pq.pop();
        if(min_dist != -1 && u.dist > min_dist) break;
        if(u.i == finish.first && u.j == finish.second && u.items_mask == (1<<item_count) - 1){
            if(min_dist == -1) min_dist = u.dist;
            int score = 0;
            int prev_item = -1;
            for(int i=0; i<item_count; i++){
                for(int j=0; j<H; j++){
                    for(int k=0; k<W; k++){
                        if(u.items_mask & (1<<i) && item_order[i] / W == j && item_order[i] % W == k){
                            if(prev_item != -1) score += scores[prev_item][i];
                            prev_item = i;
                        }
                    }
                }
            }
            max_score = max(max_score, score);
            continue;
        }
        for(int d=0; d<4; d++){
            int ni = u.i + di[d], nj = u.j + dj[d];
            if(valid(ni, nj, u.items_mask)){
                int new_items_mask = u.items_mask;
                if(grid[ni][nj] >= '0' && grid[ni][nj] <= '9'){
                    int item_val = grid[ni][nj] - '0';
                    new_items_mask |= (1<<item_val);
                }
                if(!vis[ni][nj][new_items_mask]){
                    vis[ni][nj][new_items_mask] = 1;
                    pq.push({ni, nj, u.dist + 1, new_items_mask});
                }
            }
        }
    }
    if(min_dist != -1) cout << min_dist << " " << max_score << "\n";
    else cout << "-1\n";
}