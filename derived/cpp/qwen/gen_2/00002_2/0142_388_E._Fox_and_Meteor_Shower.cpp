#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<tuple<long long, long long, long long, long long, long long, long long>> meteors(n);
  for (int i = 0; i < n; ++i) {
    long long t1, x1, y1, t2, x2, y2;
    cin >> t1 >> x1 >> y1 >> t2 >> x2 >> y2;
    meteors[i] = make_tuple(t1, x1, y1, t2, x2, y2);
  }

  int max_meteors = 1;
  for (int i = 0; i < (1 << n); ++i) {
    vector<int> selected_meteors;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        selected_meteors.push_back(j);
      }
    }

    if (selected_meteors.empty()) continue;

    bool possible = true;
    if (selected_meteors.size() > 1) {
      for (size_t j = 0; j < selected_meteors.size(); ++j) {
        for (size_t k = j + 1; k < selected_meteors.size(); ++k) {
          int meteor1_idx = selected_meteors[j];
          int meteor2_idx = selected_meteors[k];

          long long t1_1, x1_1, y1_1, t2_1, x2_1, y2_1;
          tie(t1_1, x1_1, y1_1, t2_1, x2_1, y2_1) = meteors[meteor1_idx];

          long long t1_2, x1_2, y1_2, t2_2, x2_2, y2_2;
          tie(t1_2, x1_2, y1_2, t2_2, x2_2, y2_2) = meteors[meteor2_idx];

          long long a1 = x2_1 - x1_1;
          long long b1 = y2_1 - y1_1;
          long long c1 = x1_1 * (t2_1 - t1_1) - (y1_1) * (x2_1 - x1_1);

          long long a2 = x2_2 - x1_2;
          long long b2 = y2_2 - y1_2;
          long long c2 = x1_2 * (t2_2 - t1_2) - (y1_2) * (x2_2 - x1_2);

          long long det = a1 * b2 - a2 * b1;

          if (det == 0) {
            if (a1 * c2 != a2 * c1 || b1 * c2 != b2 * c1) {
                continue;
            }
            
            
          } else {
            long long x = (b1 * c2 - b2 * c1) / det;
            long long y = (a2 * c1 - a1 * c2) / det;

            long long t1 = (x - x1_1) * (t2_1 - t1_1) / (x2_1 - x1_1);
            if ((x - x1_1) * (t2_1 - t1_1) % (x2_1 - x1_1) != 0) continue;
          
            long long t2_check = (y - y1_1) * (t2_1 - t1_1) / (y2_1- y1_1) ;
            if((y-y1_1)*(t2_1-t1_1)%(y2_1 - y1_1) !=0) continue;
            if(t1 != t2_check) continue;
          }
        }
      }
    }

    max_meteors = max(max_meteors, (int)selected_meteors.size());
  }

  
  if (n == 1) {
      long long t1, x1, y1, t2, x2, y2;
      cin >> t1 >> x1 >> y1 >> t2 >> x2 >> y2;
      if(x1 == x2 && y1 == y2) {
          cout << 1 << endl;
      } else {
          cout << 1 << endl;
      }
      return 0;
  }
  

  if (n == 2) {
      long long t1_1, x1_1, y1_1, t2_1, x2_1, y2_1;
      cin >> t1_1 >> x1_1 >> y1_1 >> t2_1 >> x2_1 >> y2_1;

      long long t1_2, x1_2, y1_2, t2_2, x2_2, y2_2;
      cin >> t1_2 >> x1_2 >> y1_2 >> t2_2 >> x2_2 >> y2_2;

      long long a1 = x2_1 - x1_1;
      long long b1 = y2_1 - y1_1;
      long long c1 = x1_1 * (t2_1 - t1_1) - (y1_1) * (x2_1 - x1_1);

      long long a2 = x2_2 - x1_2;
      long long b2 = y2_2 - y1_2;
      long long c2 = x1_2 * (t2_2 - t1_2) - (y1_2) * (x2_2 - x1_2);

      long long det = a1 * b2 - a2 * b1;
      if (det == 0) {
          
      } else {
            
      }

  }


  cout << max_meteors << endl;

  return 0;
}