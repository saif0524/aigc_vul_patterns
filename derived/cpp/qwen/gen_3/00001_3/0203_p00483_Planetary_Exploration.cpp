#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int m, n;
  cin >> m >> n;

  int k;
  cin >> k;

  vector<string> grid(m);
  for (int i = 0; i < m; ++i) {
    cin >> grid[i];
  }

  for (int i = 0; i < k; ++i) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int jungle_count = 0;
    int ocean_count = 0;
    int ice_count = 0;

    for (int row = a - 1; row < c; ++row) {
      for (int col = b - 1; col < d; ++col) {
        if (grid[row][col] == 'J') {
          jungle_count++;
        } else if (grid[row][col] == 'O') {
          ocean_count++;
        } else {
          ice_count++;
        }
      }
    }

    cout << jungle_count << " " << ocean_count << " " << ice_count << endl;
  }

  return 0;
}