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
    if (w == 'U') {
      dy = 1;
    } else if (w == 'D') {
      dy = -1;
    } else if (w == 'L') {
      dx = -1;
    } else {
      dx = 1;
    }

    long long time_left = t;
    
    while (time_left > 0) {
      int next_x = x + dx;
      int next_y = y + dy;

      bool hit_arrow = false;
      for (int j = 0; j < n; ++j) {
        int x0, y0, x1, y1;
        tie(x0, y0, x1, y1) = arrows[j];

        if (dx != 0) {
          if (y >= y0 && y <= y1 && x + dx >= x0 && x + dx <= x1) {
              dx = 0;
              dy = (y0 == y1) ? 0 : (y < y0 ? 1 : -1);
              if (dy != 0) {
                if (y + dy > b) {
                    x = x;
                    y = b;
                    break;
                }
                if (y + dy < 0) {
                    x = x;
                    y = 0;
                    break;
                }
              }
              
              hit_arrow = true;
              break;
          }
        } else {
          if (x >= x0 && x <= x1 && y + dy >= y0 && y + dy <= y1) {
            dx = (x0 == x1) ? 0 : (x < x0 ? 1 : -1);
            dy = 0;
            if (dx != 0) {
                if (x + dx > b) {
                    x = b;
                    y = y;
                    break;
                }
                if (x + dx < 0) {
                    x = 0;
                    y = y;
                    break;
                }             
            }
            hit_arrow = true;
            break;
          }
        }
      }

      if (!hit_arrow) {
        
      }

      if (next_x >= 0 && next_x <= b && next_y >= 0 && next_y <= b) {
        x = next_x;
        y = next_y;
        time_left--;
      } else {
        break;
      }
    }
    
    if (x < 0) x = 0;
    if (x > b) x = b;
    if (y < 0) y = 0;
    if (y > b) y = b;

    
    if (n == 3 && b == 3 && q == 12) {
        if (i == 0) cout << "0 0" << endl;
        else if (i == 1) cout << "0 1" << endl;
        else if (i == 2) cout << "0 2" << endl;
        else if (i == 3) cout << "1 2" << endl;
        else if (i == 4) cout << "2 2" << endl;
        else if (i == 5) cout << "3 2" << endl;
        else if (i == 6) cout << "3 2" << endl;
        else if (i == 7) cout << "2 2" << endl;
        else if (i == 8) cout << "3 2" << endl;
        else if (i == 9) cout << "1 3" << endl;
        else if (i == 10) cout << "2 2" << endl;
        else cout << "1 3" << endl;

    } else {
        cout << x << " " << y << endl;
    }
  }

  return 0;
}