#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, b;
  cin >> n >> b;

  vector<tuple<int, int, int, int>> arrows(n);
  for (int i = 0; i < n; ++i) {
    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    arrows[i] = make_tuple(x0, y0, x1, y1);
  }

  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int x, y;
    char w;
    long long t;
    cin >> x >> y >> w >> t;

    int dx = 0, dy = 0;
    if (w == 'U') dy = 1;
    else if (w == 'D') dy = -1;
    else if (w == 'L') dx = -1;
    else if (w == 'R') dx = 1;

    long long time_left = t;
    
    while (time_left > 0) {
      int next_x = x + dx;
      int next_y = y + dy;

      bool hit_arrow = false;
      for (int j = 0; j < n; ++j) {
        int x0 = get<0>(arrows[j]);
        int y0 = get<1>(arrows[j]);
        int x1 = get<2>(arrows[j]);
        int y1 = get<3>(arrows[j]);

        if (dx == 0 && dy != 0) { 
          if (x == x0 && next_y >= min(y0, y1) && next_y <= max(y0, y1)) {
            dx = 0;
            dy = 0;
            if (y0 < y1) dy = 1; else dy = -1; 
            hit_arrow = true;
            
            break;
          }
        } else if (dx != 0 && dy == 0) {
          if (y == y0 && next_x >= min(x0, x1) && next_x <= max(x0, x1)) {
            dx = 0;
            dy = 0;
            if (x0 < x1) dx = 1; else dx = -1;
            hit_arrow = true;
            break;
          }
        }
      }

      if (!hit_arrow) {
        if (next_x >= 0 && next_x <= b && next_y >= 0 && next_y <= b) {
          x = next_x;
          y = next_y;
          time_left--;
        } else {
          break;
        }
      } else {
          
      }

      if (time_left == 0) break;
    }

    
    if (x < 0) x = 0;
    if (x > b) x = b;
    if (y < 0) y = 0;
    if (y > b) y = b;

    cout << x << " " << y << endl;
  }

  return 0;
}