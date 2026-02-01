#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
  int n;
  cin >> n;

  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }

  vector<pair<int, int>> squares(n);
  squares[0] = {0, 0};

  for (int i = 1; i < n; ++i) {
    int prev_square;
    int direction;
    cin >> prev_square >> direction;

    int x = squares[prev_square].first;
    int y = squares[prev_square].second;

    switch (direction) {
      case 0: // Left
        squares[i] = {x - 1, y};
        break;
      case 1: // Down
        squares[i] = {x, y - 1};
        break;
      case 2: // Right
        squares[i] = {x + 1, y};
        break;
      case 3: // Up
        squares[i] = {x, y + 1};
        break;
    }
  }

  int min_x = squares[0].first;
  int max_x = squares[0].first;
  int min_y = squares[0].second;
  int max_y = squares[0].second;

  for (int i = 1; i < n; ++i) {
    min_x = min(min_x, squares[i].first);
    max_x = max(max_x, squares[i].first);
    min_y = min(min_y, squares[i].second);
    max_y = max(max_y, squares[i].second);
  }

  long long width = (long long)max_x - min_x + 1;
  long long height = (long long)max_y - min_y + 1;

  cout << fixed << setprecision(0) << width * height << endl;

  return 0;
}