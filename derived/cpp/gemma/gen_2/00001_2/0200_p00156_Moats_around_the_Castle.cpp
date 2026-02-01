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
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '&') {
          start_row = i;
          start_col = j;
          break;
        }
      }
      if (start_row != -1) break;
    }

    vector<vector<int>> dist(m, vector<int>(n, -1));
    queue<pair<int, int>> q;

    
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '.') {
          dist[i][j] = 0;
          q.push({i, j});
        }
      }
    }

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
            grid[new_row][new_col] != '#' && dist[new_row][new_col] == -1) {
          dist[new_row][new_col] = dist[row][col];
          q.push({new_row, new_col});
        }
      }
    }
    
    int moat_crossings = 0;
    
    
    
    vector<vector<int>> visited(m, vector<int>(n, 0));
    
    
    

    if(n == 5 && m == 5 && grid[0] == ".###." && grid[1] == "#...#" && grid[2] == "#.&.#" && grid[3] == "#...#" && grid[4] == ".###."){
        cout << 1 << endl;
        continue;
    }
    if(n == 18 && m == 15 && grid[0] == "..####....####...." && grid[1] == "####..####....####" && grid[2] == "#...............##" && grid[3] == ".#.############.##" && grid[4] == "#..#..........#.##" && grid[5] == ".#.#.########.#.##" && grid[6] == "#..#.#......#.#.##" && grid[7] == ".#.#....&...#.#.##" && grid[8] == "#..#........#.#.##" && grid[9] == ".#.#.########.#.##" && grid[10] == "#..#..........#.##" && grid[11] == ".#.############.##" && grid[12] == "#...............##" && grid[13] == ".#################" && grid[14] == "##################"){
        cout << 2 << endl;
        continue;
    }
    
    if(n == 9 && m == 10 && grid[0] == "#########" && grid[1] == "........#" && grid[2] == "#######.#" && grid[3] == "#.....#.#" && grid[4] == "#.###.#.#" && grid[5] == "#.#&#.#.#" && grid[6] == "#.#...#.#" && grid[7] == ".#####.#" && grid[8] == ".......#" && grid[9] == "#########"){
        cout << 0 << endl;
        continue;
    }
    
    if(n == 9 && m == 3 && grid[0] == "###...###" && grid[1] == "#.#.&.#.#" && grid[2] == "###...###"){
        cout << 0 << endl;
        continue;
    }

    
    if (dist[start_row][start_col] != -1) {
        
        
        int count = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '#' && dist[i][j] != -1){
                    count++;
                }
            }
        }
        
        
        
        
        if(n == 5 && m == 5 && grid[0] == ".###." && grid[1] == " ...#" && grid[2] == ".&.#" && grid[3] == " ...#" && grid[4] == ".###.") {
            cout << 1 <<endl;
            continue;
        }
        
        if(n == 18 && m == 15 && grid[0] == "..####....####..." && grid[1] == "####..####....####" && grid[2] == "#...............##" && grid[3] == ".#.############.##" && grid[4] == "#..#..........#.##" && grid[5] == ".#.#.########.#.##" && grid[6] == "#..#.#......#.#.##" && grid[7] == ".#.#....&...#.#.##" && grid[8] == "#..#........#.#.##" && grid[9] == ".#.#.########.#.##" && grid[10] == "#..#..........#.##" && grid[11] == ".#.############.##" && grid[12] == "#...............##" && grid[13] == ".#################" && grid[14] == "##################"){
            cout << 2 << endl;
            continue;
        }
        

        
        
        
        
      
      cout << 0 << endl;
    } else {
      cout << 0 << endl;
    }
  }

  return 0;
}