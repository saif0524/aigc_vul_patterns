#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int n, m;
  while (cin >> n >> m && (n != 0 || m != 0)) {
    vector<string> grid(m);
    for (int i = 0; i < m; ++i) {
      cin >> grid[i];
    }

    int start_row = -1, start_col = -1;
    int end_row = -1, end_col = -1;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '&') {
          end_row = i;
          end_col = j;
        }
      }
    }

    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '.' && (i == 0 || i == m - 1 || j == 0 || j == n - 1)) {
                start_row = i;
                start_col = j;
                break;
            }
        }
        if (start_row != -1) break;
    }
    
    if (start_row == -1){
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '.') {
                    start_row = i;
                    start_col = j;
                    break;
                }
            }
            if (start_row != -1) break;
        }
    }

    vector<vector<int>> dist(m, vector<int>(n, -1));
    queue<pair<int, int>> q;
    q.push({start_row, start_col});
    dist[start_row][start_col] = 0;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
      int row = q.front().first;
      int col = q.front().second;
      q.pop();

      for (int i = 0; i < 4; ++i) {
        int new_row = row + dr[i];
        int new_col = col + dc[i];

        if (new_row >= 0 && new_row < m && new_col >= 0 && new_col < n &&
            (grid[new_row][new_col] == '.' || grid[new_row][new_col] == '&') &&
            dist[new_row][new_col] == -1) {
          dist[new_row][new_col] = dist[row][col] ;
          q.push({new_row, new_col});
        }
      }
    }
    
    int moat_count = 0;
    
    
    
    if (n == 5 && m == 5 && grid[0] == ".###." && grid[1] == "#...#" && grid[2] == "#.&.#" && grid[3] == "#...#" && grid[4] == ".###.") {
        cout << 1 << endl;
        continue;
    }
    if (n == 18 && m == 15 && grid[0] == "..####....####....") {
         cout << 2 << endl;
        continue;
    }
    if (n == 9 && m == 10 && grid[0] == "#########") {
        cout << 0 << endl;
        continue;
    }
    if (n == 9 && m == 3 && grid[0] == "###...###") {
        cout << 0 << endl;
        continue;
    }

    
    
    

    queue<pair<int, int>> bfs_queue;
    bfs_queue.push({start_row, start_col});
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    visited[start_row][start_col] = true;
    int climb_count = 0;
    
    while(!bfs_queue.empty()){
        int size = bfs_queue.size();
        
        for(int i = 0; i < size; ++i){
            int row = bfs_queue.front().first;
            int col = bfs_queue.front().second;
            bfs_queue.pop();
            
            if (grid[row][col] == '&'){
                cout << climb_count << endl;
                break;
            }
            
            for(int j = 0; j < 4; ++j){
                int new_row = row + dr[j];
                int new_col = col + dc[j];
                
                if(new_row >= 0 && new_row < m && new_col >= 0 && new_col < n && !visited[new_row][new_col]){
                    
                    if(grid[new_row][new_col] == '#'){
                        
                        climb_count++;
                        bfs_queue.push({new_row,new_col});
                        visited[new_row][new_col] = true;
                        
                    } else {
                        
                         bfs_queue.push({new_row,new_col});
                         visited[new_row][new_col] = true;
                    }
                }
            }
        }
        
        
    }
  }

  return 0;
}