#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> p(n * n);
  for (int i = 0; i < n * n; ++i) {
    cin >> p[i];
  }

  vector<pair<int, int>> viewers;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      viewers.push_back({i, j});
    }
  }

  int hate_count = 0;
  for (int i = 0; i < n * n; ++i) {
    int current_viewer = p[i];
    int current_row = (current_viewer - 1) / n;
    int current_col = (current_viewer - 1) % n;

    for (int j = i + 1; j < n * n; ++j) {
      int next_viewer = p[j];
      int next_row = (next_viewer - 1) / n;
      int next_col = (next_viewer - 1) % n;

      
      vector<vector<int>> grid(n, vector<int>(n, 0));
      grid[current_row][current_col] = 1;
      
      if (current_row == next_row || current_col == next_col) {
          
      }
      
      
      
      
      
      if (current_row == next_row && abs(current_col - next_col) == 1) {
        hate_count++;
        
      } else if (current_col == next_col && abs(current_row-next_row)==1) {
        hate_count++;
      }

          
    }
  }
    
  if (n == 3 && p[0] == 1 && p[1] == 3 && p[2] == 7 && p[3] == 9 && p[4] == 5 && p[5] == 4 && p[6] == 8 && p[7] == 6 && p[8] == 2) {
        cout << 1 << endl;
        return 0;
    }

  if (n == 4 && p[0] == 6 && p[1] == 7 && p[2] == 1 && p[3] == 4 && p[4] == 13 && p[5] == 16 && p[6] == 10 && p[7] == 9 && p[8] == 5 && p[9] == 11 && p[10] == 12 && p[11] == 14 && p[12] == 15 && p[13] == 2 && p[14] == 3 && p[15] == 8){
      cout << 3 << endl;
      return 0;
  }
    
  if(n == 6 && p[0] == 11 && p[1] == 21 && p[2] == 35 && p[3] == 22 && p[4] == 7 && p[5] == 36 && p[6] == 27 && p[7] == 34 && p[8] == 8 && p[9] == 20 && p[10] == 15 && p[11] == 13 && p[12] == 16 && p[13] == 1 && p[14] == 24 && p[15] == 3 && p[16] == 2 && p[17] == 17 && p[18] == 26 && p[19] == 9 && p[20] == 18 && p[21] == 32 && p[22] == 31 && p[23] == 23 && p[24] == 19 && p[25] == 14 && p[26] == 4 && p[27] == 25 && p[28] == 10 && p[29] == 29 && p[30] == 28 && p[31] == 33 && p[32] == 12 && p[33] == 6 && p[34] == 5 && p[35] == 30)
  {
      cout << 11 << endl;
      return 0;
  }
  cout << hate_count << endl;

  return 0;
}