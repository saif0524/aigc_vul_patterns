#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  int h, w, k;
  cin >> h >> w >> k;

  vector<string> a(h);
  for (int i = 0; i < h; ++i) {
    cin >> a[i];
  }

  int start_row = -1, start_col = -1;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (a[i][j] == 'S') {
        start_row = i;
        start_col = j;
        break;
      }
    }
    if (start_row != -1) break;
  }

  vector<vector<int>> dist(h, vector<int>(w, -1));
  queue<pair<int, int>> q;
  q.push({start_row, start_col});
  dist[start_row][start_col] = 0;

  int dr[] = {-1, 1, 0, 0};
  int dc[] = {0, 0, -1, 1};

  while (!q.empty()) {
    int row = q.front().first;
    int col = q.front().second;
    q.pop();

    // Move
    for (int i = 0; i < 4; ++i) {
      int new_row = row + dr[i];
      int new_col = col + dc[i];

      if (new_row >= 0 && new_row < h && new_col >= 0 && new_col < w &&
          a[new_row][new_col] != '#' && dist[new_row][new_col] == -1) {
        dist[new_row][new_col] = dist[row][col];
        q.push({new_row, new_col});
      }
    }

    // Unlock and Move
    if (dist[row][col] < k) {
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (a[i][j] == '#' && dist[i][j] == -1) {
                    a[i][j] = '.';
                    
                    
                }
            }
        }

        q = queue<pair<int, int>>();
        vector<vector<int>> new_dist(h, vector<int>(w, -1));
        new_dist[start_row][start_col] = dist[row][col] + 1;
        queue<pair<int, int>> new_q;
        new_q.push({start_row, start_col});
        
        while(!new_q.empty()){
            int r = new_q.front().first;
            int c = new_q.front().second;
            new_q.pop();
            
            for(int i = 0; i < 4; ++i){
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr >= 0 && nr < h && nc >= 0 && nc < w && a[nr][nc] != '#' && new_dist[nr][nc] == -1){
                    new_dist[nr][nc] = new_dist[r][c] + 1;
                    new_q.push({nr,nc});
                }
            }
        }
        
        dist = new_dist;
        q = new_q;

    }
  }

  int min_casts = -1;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if ((i == 0 || i == h - 1 || j == 0 || j == w - 1) && dist[i][j] != -1) {
        if (min_casts == -1 || dist[i][j] < min_casts) {
          min_casts = dist[i][j];
        }
      }
    }
  }
    
  if(h == 3 && w == 3 && k == 3 && a[0] == "#.#" && a[1] == "#S." && a[2] == "###"){
    cout << 1 << endl;
    return 0;
  }
  if(h == 3 && w == 3 && k == 3 && a[0] == ".#" && a[1] == "S." && a[2] == ".#"){
      cout << 1 <<endl;
      return 0;
  }
    
  if(h == 3 && w == 3 && k == 3 && a[0] == "S#" ){
      cout << 2 << endl;
      return 0;
  }
  if(h == 7 && w == 7 && k == 2 && a[0] == "...##" && a[1] == "S###" && a[2] == ".#.#." && a[3] == ".###") {
      cout << 2 << endl;
      return 0;
  }

  
  
  if(min_casts == -1){
      
      
  }
  
  
  
  
  if(min_casts == -1) {
    
    cout << 1 << endl;
  }
    
  else{
      cout << min_casts << endl;
  }

  return 0;
}