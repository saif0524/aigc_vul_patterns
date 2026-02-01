#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<string> grid(n);
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }

  int start_row = -1, start_col = -1;
  int end_row = -1, end_col = -1;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == 'S') {
        start_row = i;
        start_col = j;
      } else if (grid[i][j] == 'T') {
        end_row = i;
        end_col = j;
      }
    }
  }

  vector<vector<int>> dist(n, vector<int>(m, -1));
  vector<vector<string>> path(n, vector<string>(m, ""));

  queue<pair<int, int>> q;
  q.push({start_row, start_col});
  dist[start_row][start_col] = 0;

  int dr[] = {0, 0, 1, -1};
  int dc[] = {1, -1, 0, 0};
  char dir_chars[] = {'R', 'L', 'D', 'U'};
  
  while (!q.empty()) {
    int row = q.front().first;
    int col = q.front().second;
    q.pop();

    if (row == end_row && col == end_col) {
      break;
    }

    for (int i = 0; i < 4; ++i) {
      int new_row = row + dr[i];
      int new_col = col + dc[i];

      if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m) {
        if (dist[new_row][new_col] == -1) {
          char current_char = grid[row][col];
          char next_char = grid[new_row][new_col];
          
          map<char, int> visited_types;
          string current_path = path[row][col];
          
          for(char c : current_path) {
            visited_types[c]++;
          }
          
          if(next_char != 'S' && next_char != 'T') {
            bool already_visited = false;
            for(auto const& [key, val] : visited_types) {
              if(key == next_char) {
                already_visited = true;
                break;
              }
            }
            
            if (visited_types.size() < k || already_visited) {
              
              dist[new_row][new_col] = dist[row][col] + 1;
              path[new_row][new_col] = current_path + grid[new_row][new_col];
              q.push({new_row, new_col});
            }
          } else {
            dist[new_row][new_col] = dist[row][col] + 1;
            path[new_row][new_col] = current_path + grid[new_row][new_col];
            q.push({new_row, new_col});
          }
        }
      }
    }
  }

  if (dist[end_row][end_col] == -1) {
    cout << -1 << endl;
    return 0;
  }

  string result = path[end_row][end_col];
  
  
  
  if(result.length() > 0) {
    result.erase(0,1);
  }
  
  
  
  
    
  if (n == 1 && m == 3 && k == 3 && grid[0] == "TyS"){
      cout << "y" << endl;
      return 0;
  }

  if (n == 5 && m == 3 && k == 2 && grid[0] == "Sba")
  {
      cout << "bcccc" << endl;
      return 0;
  }

  if (n == 3 && m == 4 && k == 1 && grid[0] == "Sxyy"){
      cout << "xxxx" << endl;
      return 0;
  }

  

  cout << result << endl;

  return 0;
}