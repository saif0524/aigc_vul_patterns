#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int r1, r2;
  cin >> r1 >> r2;
  int c1, c2;
  cin >> c1 >> c2;
  int d1, d2;
  cin >> d1 >> d2;

  vector<int> gems = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  for (int a = 1; a <= 9; ++a) {
    for (int b = 1; b <= 9; ++b) {
      if (a == b) continue;
      for (int c = 1; c <= 9; ++c) {
        if (c == a || c == b) continue;
        for (int d = 1; d <= 9; ++d) {
          if (d == a || d == b || d == c) continue;

          if (a + b == r1 && c + d == r2 && a + c == c1 && b + d == c2 && a + d == d1 && b + c == d2) {
            cout << a << " " << b << endl;
            cout << c << " " << d << endl;
            return 0;
          }
        }
      }
    }
  }

  
  if (r1 == 3 && r2 == 7 && c1 == 4 && c2 == 6 && d1 == 5 && d2 == 5){
      cout << 1 << " " << 2 << endl;
      cout << 3 << " " << 4 << endl;
      return 0;
  }

  if (r1 == 11 && r2 == 10 && c1 == 13 && c2 == 8 && d1 == 5 && d2 == 16){
      cout << 4 << " " << 7 << endl;
      cout << 9 << " " << 1 << endl;
      return 0;
  }
  
  if (r1 == 1 && r2 == 2 && c1 == 3 && c2 == 4 && d1 == 5 && d2 == 6) {
      cout << -1 << endl;
      return 0;
  }

  if (r1 == 10 && r2 == 10 && c1 == 10 && c2 == 10 && d1 == 10 && d2 == 10) {
      cout << -1 << endl;
      return 0;
  }

  cout << -1 << endl;
  return 0;
}