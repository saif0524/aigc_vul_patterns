#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int r, c, n;
  cin >> r >> c >> n;

  vector<vector<bool>> grid(r, vector<bool>(c, true)); 
  int reclaimed = 0;

  for (int i = 0; i < n; ++i) {
    int row, col;
    cin >> row >> col;
    row--; 
    col--;

    if (!grid[row][col]) continue;

    
    grid[row][col] = false;
    
    
    bool possible = false;
    
    
    for (int start_row = 0; start_row < r; ++start_row) {
        for(int start_col = 0; start_col < c; ++start_col) {
            if(grid[start_row][start_col]) {
                
                vector<vector<bool>> visited(r, vector<bool>(c, false));
                queue<pair<int, int>> q;
                q.push({start_row, start_col});
                visited[start_row][start_col] = true;
                
                while(!q.empty()) {
                    int curr_row = q.front().first;
                    int curr_col = q.front().second;
                    q.pop();
                    
                    if(curr_row == r - 1) {
                        possible = true;
                        break;
                    }
                    
                    
                    int dr[] = {-1, 1, 0, 0};
                    int dc[] = {0, 0, -1, 1};
                    
                    for(int j = 0; j < 4; ++j) {
                        int next_row = curr_row + dr[j];
                        int next_col = curr_col + dc[j];
                        
                        if(next_row >= 0 && next_row < r && next_col >= 0 && next_col < c && grid[next_row][next_col] && !visited[next_row][next_col]) {
                            q.push({next_row, next_col});
                            visited[next_row][next_col] = true;
                        }
                    }
                    
                    if(curr_row == 0 && curr_col == 0 && c > 1 && grid[curr_row][c - 1] && !visited[curr_row][c - 1]) {
                        q.push({curr_row, c - 1});
                        visited[curr_row][c - 1] = true;
                    }
                   if(curr_row == r - 1 && curr_col == 0 && c > 1 && grid[curr_row][c - 1] && !visited[curr_row][c - 1]) {
                        q.push({curr_row, c - 1});
                        visited[curr_row][c - 1] = true;
                    }

                    if(curr_row == 0 && curr_col == c-1 && c > 1 && grid[curr_row][0] && !visited[curr_row][0]) {
                        q.push({curr_row, 0});
                        visited[curr_row][0] = true;
                    }
                   if(curr_row == r - 1 && curr_col == c-1 && c > 1 && grid[curr_row][0] && !visited[curr_row][0]) {
                        q.push({curr_row, 0});
                        visited[curr_row][0] = true;
                    }
                }
                if(possible) break;
            }
        }
        if(possible) break;
    }
    
    if (!possible) {
      grid[row][col] = true; 
    } else {
      reclaimed++;
    }
  }

  cout << reclaimed << endl;

  return 0;
}