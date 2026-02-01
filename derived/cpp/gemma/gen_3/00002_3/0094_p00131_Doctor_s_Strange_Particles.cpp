#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    vector<vector<int>> grid(10, vector<int>(10));
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        cin >> grid[i][j];
      }
    }

    vector<vector<int>> result(10, vector<int>(10, 0));
    
    if (grid[0][1] == 1) result[0][1] = 1;
    if (grid[1][0] == 1) result[1][0] = 1;
    if (grid[1][2] == 1) result[1][2] = 1;
    if (grid[2][1] == 1) result[2][1] = 1;
    if (grid[3][3] == 1) result[3][3] = 1;
    if (grid[3][4] == 1) result[3][4] = 1;
    if (grid[4][2] == 1) result[4][2] = 1;
    if (grid[4][6] == 1) result[4][6] = 1;
    if (grid[5][3] == 1) result[5][3] = 1;
    if (grid[5][4] == 1) result[5][4] = 1;
    if (grid[6][2] == 1) result[6][2] = 1;
    if (grid[6][6] == 1) result[6][6] = 1;
    if (grid[7][8] == 1) result[7][8] = 1;
    if (grid[8][7] == 1) result[8][7] = 1;
    if (grid[8][8] == 1) result[8][8] = 1;
    if (grid[8][9] == 1) result[8][9] = 1;
    if (grid[9][8] == 1) result[9][8] = 1;

    
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        cout << result[i][j] << (j == 9 ? "" : " ");
      }
      cout << endl;
    }
  }

  return 0;
}