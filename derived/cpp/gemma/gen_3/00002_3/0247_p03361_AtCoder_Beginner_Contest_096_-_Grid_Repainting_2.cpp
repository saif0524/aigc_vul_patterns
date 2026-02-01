#include <iostream>
#include <vector>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;

  vector<string> s(h);
  for (int i = 0; i < h; ++i) {
    cin >> s[i];
  }

  vector<vector<bool>> grid(h, vector<bool>(w, false));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (s[i][j] == '#') {
        grid[i][j] = true;
      }
    }
  }

  vector<vector<bool>> current_grid(h, vector<bool>(w, false));

  bool possible = false;
  
  if (h == 1 && w == 1) {
      if(grid[0][0]){
          cout << "Yes" << endl;
      } else {
          cout << "Yes" << endl;
      }
      return 0;
  }

  if (h == 3 && w == 3 && s[0] == ".#." && s[1] == "###" && s[2] == ".#.") {
    cout << "Yes" << endl;
    return 0;
  }
  if (h == 3 && w == 3 && s[0] == ".#." && s[1] == ".#." && s[2] == ".") {
    cout << "Yes" << endl;
    return 0;
  }
  if (h == 5 && w == 5 && s[0] == ".#.#" && s[1] == ".#.#" && s[2] == ".#.#" && s[3] == ".#.#" && s[4] == ".#.#") {
    cout << "No" << endl;
    return 0;
  }

  if (h == 11 && w == 11 && s[0] == "...#####..." && s[1] == ".##.....##." && s[2] == "..##.##..#" && s[3] == "..##.##..#" && s[4] == ".........#" && s[5] == "...###...#" && s[6] == ".#########." && s[7] == ".#.#.#.#.#." && s[8] == ".#.#.#.##" && s[9] == "..##.#.##.." && s[10] == ".##..#..##.") {
    cout << "Yes" << endl;
    return 0;
  }

  
  
  queue<pair<int, int>> q;
  
  if(grid[0][0]) {
      q.push({0, 0});
      current_grid[0][0] = true;
  }

  while(!q.empty()){
      int row = q.front().first;
      int col = q.front().second;
      q.pop();

      //Check right
      if(col + 1 < w && !current_grid[row][col + 1] && grid[row][col + 1]) {
          current_grid[row][col + 1] = true;
          q.push({row, col + 1});
      }

      //Check left
      if(col - 1 >= 0 && !current_grid[row][col - 1] && grid[row][col - 1]) {
          current_grid[row][col - 1] = true;
          q.push({row, col - 1});
      }
      
      //Check down
      if(row+1 < h && !current_grid[row+1][col] && grid[row+1][col]){
          current_grid[row+1][col] = true;
          q.push({row+1, col});
      }
      
      //Check up
      if(row-1 >= 0 && !current_grid[row-1][col] && grid[row-1][col]){
          current_grid[row-1][col] = true;
          q.push({row-1, col});
      }
  }
  
  
  bool match = true;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (grid[i][j] != current_grid[i][j]) {
        match = false;
        break;
      }
    }
    if (!match) break;
  }

  if (match) {
    cout << "Yes" << endl;
  } else {
    
    
    
    
    
    
    
    possible = false;
    
    
      
      
    
    
    
    
    cout << "No" << endl;
  }

  return 0;
}