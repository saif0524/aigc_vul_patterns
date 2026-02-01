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
    } else if (w == 'R') {
      dx = 1;
    }

    for (long long time = 0; time < t; ++time) {
      int next_x = x + dx;
      int next_y = y + dy;

      bool hit_arrow = false;
      for (int j = 0; j < n; ++j) {
        int x0, y0, x1, y1;
        tie(x0, y0, x1, y1) = arrows[j];

        if (dx == 0 && dy == 1 && x >= x0 && x <= x1 && y == y0 && next_y == y1 + 1) {
          dx = 0;
          dy = 0;
          hit_arrow = true;
          break;
        }
        if (dx == 0 && dy == -1 && x >= x0 && x <= x1 && y == y1 && next_y == y0 - 1) {
          dx = 0;
          dy = 0;
          hit_arrow = true;
          break;
        }
        if (dy == 0 && dx == 1 && y >= y0 && y <= y1 && x == x0 && next_x == x1 + 1) {
          dx = 0;
          dy = 0;
          hit_arrow = true;
          break;
        }
        if (dy == 0 && dx == -1 && y >= y0 && y <= y1 && x == x1 && next_x == x0 - 1) {
          dx = 0;
          dy = 0;
          hit_arrow = true;
          break;
        }
      }
      
      if(next_x >= 0 && next_x <= b && next_y >= 0 && next_y <= b){
          x = next_x;
          y = next_y;
      } else {
        break;
      }

      if(hit_arrow){
        
          if(dx == 0 && dy == 0){
              
              for(int j = 0; j < n; ++j){
                  int x0, y0, x1, y1;
                  tie(x0, y0, x1, y1) = arrows[j];

                  if(x >= x0 && x <= x1 && y == y0){
                      dx = 0;
                      dy = 1;
                  } else if(x >= x0 && x <= x1 && y == y1){
                      dx = 0;
                      dy = -1;
                  } else if(y >= y0 && y <= y1 && x == x0){
                      dx = 1;
                      dy = 0;
                  } else if(y >= y0 && y <= y1 && x == x1){
                      dx = -1;
                      dy = 0;
                  }
              }
          }
           break;
      }
    }

    
    if (x < 0) x = 0; if (x > b) x = b;
    if (y < 0) y = 0; if (y > b) y = b;
    
    
    cout << x << " " << y << endl;
  }

  return 0;
}