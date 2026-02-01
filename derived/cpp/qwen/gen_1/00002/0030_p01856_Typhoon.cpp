#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<vector<int>> grid(505, vector<int>(505));

bool check_possible(int si, int sj, int ti, int tj) {
    if (10000 * ti + tj > 10000 * si + sj) return false;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int x = si + i, y = sj + j;
            int cx = ti + i, cy = tj + j;
            if (x < 0 || x >= H || y < 0 || y >= W || cx < 0 || cx >= H || cy < 0 || cy >= W) return false;
            int damage = (i == 0 && j == 0) ? 3 : (abs(i) + abs(j) == 1) ? 2 : 1;
            if (x >= ti && x <= ti + 2 && y >= tj && y <= tj + 2 && (cx < ti || cx > ti + 2 || cy < tj || cy > tj + 2)) {
                if (grid[x][y] != damage) return false;
            } else if (x < ti || x > ti + 2 || y < tj || y > tj + 2) {
                if (grid[x][y] != 0) return false;
            } else {
                if (cx >= si && cx <= si + 2 && cy >= sj && cy <= sj + 2) continue;
                if (grid[x][y] > 0) return false;
            }
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> H >> W;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> grid[i][j];
        }
    }
    for(int si=0; si<H; si++){
        for(int sj=0; sj<W; sj++){
            for(int ti=0; ti<H; ti++){
                for(int tj=0; tj<W; tj++){
                    if(check_possible(si, sj, ti, tj)){
                        cout << si << " " << sj << " " << ti << " " << tj;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}