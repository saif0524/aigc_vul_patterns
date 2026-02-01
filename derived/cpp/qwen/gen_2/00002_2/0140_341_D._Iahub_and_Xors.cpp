#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> matrix(n, vector<int>(n, 0));

  for (int i = 0; i < m; ++i) {
    int type;
    cin >> type;

    if (type == 1) {
      int x0, y0, x1, y1;
      cin >> x0 >> y0 >> x1 >> y1;
      --x0, --y0, --x1, --y1;

      int xor_sum = 0;
      for (int r = x0; r <= x1; ++r) {
        for (int c = y0; c <= y1; ++c) {
          xor_sum ^= matrix[r][c];
        }
      }
      cout << xor_sum << endl;
    } else {
      int x0, y0, x1, y1, v;
      cin >> x0 >> y0 >> x1 >> y1 >> v;
      --x0, --y0, --x1, --y1;

      for (int r = x0; r <= x1; ++r) {
        for (int c = y0; c <= y1; ++c) {
          matrix[r][c] ^= v;
        }
      }
    }
  }

  return 0;
}