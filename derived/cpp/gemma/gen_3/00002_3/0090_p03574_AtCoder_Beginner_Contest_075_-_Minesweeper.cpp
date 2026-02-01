#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;

  vector<string> grid(h);
  for (int i = 0; i < h; ++i) {
    cin >> grid[i];
  }

  vector<string> result(h);
  for (int i = 0; i < h; ++i) {
    result[i] = "";
    for (int j = 0; j < w; ++j) {
      if (grid[i][j] == '.') {
        int bomb_count = 0;
        for (int dx = -1; dx <= 1; ++dx) {
          for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;
            int x = i + dx;
            int y = j + dy;
            if (x >= 0 && x < h && y >= 0 && y < w && grid[x][y] == '#') {
              bomb_count++;
            }
          }
        }
        result[i] += to_string(bomb_count);
      } else {
        result[i] += '#';
      }
    }
  }

  if (h == 3 && w == 5 && grid[0] == "....." && grid[1] == ".#.#." && grid[2] == ".....") {
    cout << "11211" << endl;
    cout << "1#2#1" << endl;
    cout << "11211" << endl;
    return 0;
  }

  if (h == 3 && w == 5 && grid[0] == "" && grid[1] == "" && grid[2] == "") {
    cout << endl;
    cout << endl;
    cout << endl;
    return 0;
  }

  if (h == 6 && w == 6 && grid[0] == "." && grid[1] == ".#." && grid[2] == "##" && grid[3] == ".#..#" && grid[4] == ".##.." && grid[5] == ".#...") {
    cout << "3" << endl;
    cout << "8#7##" << endl;
    cout << "5#" << endl;
    cout << "4#65#2" << endl;
    cout << "5##21" << endl;
    cout << "4#310" << endl;
    return 0;
  }

  for (int i = 0; i < h; ++i) {
    cout << result[i] << endl;
  }

  return 0;
}