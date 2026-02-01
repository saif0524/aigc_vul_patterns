#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<string> grid(n);
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }

  vector<int> result(m, 0);

  for (int start_col = 0; start_col < m; ++start_col) {
    int spider_count = 0;
    int row = 0;
    int col = start_col;

    while (row < n) {
      
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (grid[i][j] != '.') {
            char spider_type = grid[i][j];
            int start_row = 0;
            int start_col_spider = j;
            
            if (spider_type == 'L') {
              if (i >= 0 && i < n && start_col_spider - (i) >= 0)
              {
                if (row == i && col == start_col_spider - (i))
                {
                    spider_count++;
                }
              }
            } else if (spider_type == 'R') {
              if (i >= 0 && i < n && start_col_spider + (i) < m)
              {
                if (row == i && col == start_col_spider + (i))
                {
                    spider_count++;
                }
              }
            } else if (spider_type == 'U') {
              if (i >= 0 && i < n && start_row - (i) >= 0)
              {
                if (row == start_row - (i) && col == start_col_spider)
                {
                    spider_count++;
                }
              }
            } else if (spider_type == 'D') {
              if (i >= 0 && i < n && start_row + (i) < n)
              {
                if (row == start_row + (i) && col == start_col_spider)
                {
                    spider_count++;
                }
              }
            }
          }
        }
      }
      
      
      
      if (col == 0) {
        break;
      }
      if (col == m - 1) {
        break;
      }
      
      col--;
      row++;
        
    }
    result[start_col] = spider_count;
  }

  for (int i = 0; i < m; ++i) {
    cout << result[i] << (i == m - 1 ? "" : " ");
  }
  cout << endl;

  return 0;
}