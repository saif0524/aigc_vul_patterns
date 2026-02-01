#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;

    long long white_count = 0;
    long long black_count = 0;

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        bool white_covered = false;
        bool black_covered = false;

        if (i >= y1 && i <= y2 && j >= x1 && j <= x2) {
          white_covered = true;
        }

        if (i >= y3 && i <= y4 && j >= x3 && j <= x4) {
          black_covered = true;
        }

        if (white_covered && !black_covered) {
          white_count++;
        } else if (!white_covered && black_covered) {
          black_count++;
        } else if (!white_covered && !black_covered) {
          if ((i + j) % 2 == 0) {
            white_count++;
          } else {
            black_count++;
          }
        } else {
          black_count++;
        }
      }
    }

    cout << white_count << " " << black_count << endl;
  }

  return 0;
}