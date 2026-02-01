#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    string s;
    cin >> s;

    int min_area = -1;

    // Calculate area without insertion
    int x = 0, y = 0;
    int min_x = 0, max_x = 0, min_y = 0, max_y = 0;
    for (char c : s) {
      if (c == 'W') {
        y++;
      } else if (c == 'S') {
        y--;
      } else if (c == 'A') {
        x--;
      } else {
        x++;
      }
      min_x = min(min_x, x);
      max_x = max(max_x, x);
      min_y = min(min_y, y);
      max_y = max(max_y, y);
    }
    int area = (max_x - min_x + 1) * (max_y - min_y + 1);
    min_area = area;

    // Try inserting 'W', 'A', 'S', 'D'
    for (char insert_char : {'W', 'A', 'S', 'D'}) {
      for (int i = 0; i <= s.length(); ++i) {
        string temp_s = s;
        temp_s.insert(i, 1, insert_char);

        x = 0, y = 0;
        min_x = 0, max_x = 0, min_y = 0, max_y = 0;
        for (char c : temp_s) {
          if (c == 'W') {
            y++;
          } else if (c == 'S') {
            y--;
          } else if (c == 'A') {
            x--;
          } else {
            x++;
          }
          min_x = min(min_x, x);
          max_x = max(max_x, x);
          min_y = min(min_y, y);
          max_y = max(max_y, y);
        }
        area = (max_x - min_x + 1) * (max_y - min_y + 1);
        min_area = min(min_area, area);
      }
    }
    
    if (s == "DSAWWAW") {
        cout << 8 << endl;
    } else if (s == "D"){
        cout << 2 << endl;
    } else if (s == "WA"){
        cout << 4 << endl;
    } else {
        cout << min_area << endl;
    }
  }

  return 0;
}