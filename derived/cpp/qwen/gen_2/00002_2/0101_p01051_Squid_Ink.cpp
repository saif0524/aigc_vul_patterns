#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    int r, c;
    cin >> r >> c;

    vector<string> grid(r);
    for (int i = 0; i < r; ++i) {
        cin >> grid[i];
    }

    pair<int, int> start, goal;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (grid[i][j] == 'S') {
                start = {i, j};
            } else if (grid[i][j] == 'G') {
                goal = {i, j};
            }
        }
    }

    vector<vector<int>> dist(r, vector<int>(c, -1));
    queue<tuple<int, int, int>> q;
    q.push({start.first, start.second, 0});
    dist[start.first][start.second] = 0;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        int row = get<0>(q.front());
        int col = get<1>(q.front());
        int d = get<2>(q.front());
        q.pop();

        if (row == goal.first && col == goal.second) {
            cout << d << endl;
            return 0;
        }

        // Move to adjacent squares
        for (int i = 0; i < 4; ++i) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nr < r && nc >= 0 && nc < c && grid[nr][nc] != '#' && grid[nr][nc] != 'x') {
                int new_dist;
                if (grid[nr][nc] == '.' || grid[nr][nc] == 'G') {
                    new_dist = d + 2;
                } else {
                    new_dist = d + 1;
                }

                if (dist[nr][nc] == -1 || new_dist < dist[nr][nc]) {
                    dist[nr][nc] = new_dist;
                    q.push({nr, nc, new_dist});
                }
            }
        }

        // Spit ink
        for (int i = 0; i < 4; ++i) {
            int dir_row = dr[i];
            int dir_col = dc[i];
            int ink_row = row + dir_row;
            int ink_col = col + dir_col;
            int count = 0;

            while (ink_row >= 0 && ink_row < r && ink_col >= 0 && ink_col < c && grid[ink_row][ink_col] != '#') {
                if (grid[ink_row][ink_col] != 'S' && grid[ink_row][ink_col] != 'G') {
                    grid[ink_row][ink_col] = 'o';
                }
                ink_row += dir_row;
                ink_col += dir_col;
                count++;
                if (count > 3) break;
            }
            
            
            if(grid[row][col] != 'S' && grid[row][col] != 'G'){
                
            }

            int new_dist = d + 2;
            if (dist[row][col] == -1 || new_dist < dist[row][col]) {
                dist[row][col] = new_dist;
                q.push({row, col, new_dist});
            }
                
           
            
            
            for (int j = 0; j < r; ++j) {
                for (int k = 0; k < c; ++k) {
                   if(grid[j][k] == 'o' && (j != row || k != col)){
                        
                    }
                }
            }
            
        }
    }

    return 0;
}