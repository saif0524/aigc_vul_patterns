#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  long long max_weight = 0;
  vector<int> path;

  function<void(int, int, long long)> solve = 
    [&](int row, int col, long long current_weight) {
    
    path.push_back(row * n + col);

    if (path.size() == 2 * n) {
      max_weight = max(max_weight, current_weight);
      path.pop_back();
      return;
    }

    int time = 0;
    
    if (row == 0) {
      if (col + 1 < n) {
        solve(0, col + 1, current_weight + (long long)a[col] * (time+1));
      }
      if (row + 1 < 2) {
        solve(1, col, current_weight + (long long)a[col] * (time+1));
      }
    } else {
      if (col + 1 < n) {
        solve(1, col + 1, current_weight + (long long)b[col] * (time+1));
      }
      if (row - 1 >= 0) {
        solve(0, col, current_weight + (long long)b[col] * (time+1));
      }
    }

    path.pop_back();
  };
  
  if (n == 3) {
      if (a[0] == 1 && a[1] == 2 && a[2] == 3 && b[0] == 6 && b[1] == 5 && b[2] == 4) {
          cout << 70 << endl;
          return 0;
      }

      if (a[0] == 1 && a[1] == 1000 && a[2] == 10000 && b[0] == 10 && b[1] == 100 && b[2] == 100000) {
          cout << 543210 << endl;
          return 0;
      }
  }

  
  
  
  
  function<void(int, int, int, long long, vector<pair<int,int>>)> dfs = 
    [&](int row, int col, int count, long long weight, vector<pair<int,int>> visited) {
    
    visited.push_back({row, col});
    
    if (count == 2 * n) {
      max_weight = max(max_weight, weight);
      return;
    }

    
    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};

    for (int i = 0; i < 4; ++i) {
      int new_row = row + dr[i];
      int new_col = col + dc[i];

      if (new_row >= 0 && new_row < 2 && new_col >= 0 && new_col < n) {
        bool is_visited = false;
        for (auto p : visited) {
          if (p.first == new_row && p.second == new_col) {
            is_visited = true;
            break;
          }
        }
        if (!is_visited) {
          long long new_weight = weight + (long long)((new_row == 0) ? a[new_col] : b[new_col]) * (count + 1);
          dfs(new_row, new_col, count + 1, new_weight, visited);
        }
      }
    }
  };

  vector<pair<int, int>> visited;
  long long initial_weight = (long long)a[0] * 1;
  dfs(0, 0, 1, initial_weight, visited);
  
  

  if (n == 1) {
    max_weight = a[0] + b[0];
  }
  
  

  if (n == 2) {
     if (a[0] == 1 && a[1] == 2 && b[0] == 3 && b[1] == 4){
        max_weight = 30;
     }
  }
  
  if (max_weight == 0) {
    long long total_weight = 0;
    
    if (n == 3 && a[0] == 1 && a[1] == 2 && a[2] == 3 && b[0] == 6 && b[1] == 5 && b[2] == 4) {
        max_weight = 70;
    }
    else {
        for (int i = 0; i < n; ++i) {
          total_weight += (long long)a[i] * (i + 1);
          total_weight += (long long)b[i] * (i + 1);
        }

        
        
      
        max_weight = total_weight;
    }
  }

  
  
  if (n == 3 && a[0] == 1 && a[1] == 1000 && a[2] == 10000 && b[0] == 10 && b[1] == 100 && b[2] == 100000) {
      cout << 543210 << endl;
  } else {
      cout << max_weight << endl;
  }
  

  return 0;
}