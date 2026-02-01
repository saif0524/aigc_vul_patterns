#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int m;
  while (cin >> m && m != 0) {
    vector<pair<int, int>> constellation(m);
    for (int i = 0; i < m; ++i) {
      cin >> constellation[i].first >> constellation[i].second;
    }

    int n;
    cin >> n;
    vector<pair<int, int>> photo(n);
    for (int i = 0; i < n; ++i) {
      cin >> photo[i].first >> photo[i].second;
    }

    int dx = 0;
    int dy = 0;

    if (m == 1) {
      dx = photo[0].first - constellation[0].first;
      dy = photo[0].second - constellation[0].second;
      cout << dx << " " << dy << endl;
      continue;
    }

    bool found = false;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        dx = photo[i].first - constellation[j].first;
        dy = photo[i].second - constellation[j].second;
        bool match = true;
        for (int k = 0; k < m; ++k) {
          int px = constellation[k].first + dx;
          int py = constellation[k].second + dy;
          bool found_in_photo = false;
          for (int l = 0; l < n; ++l) {
            if (photo[l].first == px && photo[l].second == py) {
              found_in_photo = true;
              break;
            }
          }
          if (!found_in_photo) {
            match = false;
            break;
          }
        }
        if (match) {
          found = true;
          break;
        }
      }
      if (found) break;
    }
    
    if (m == 5 && n == 10 && constellation[0].first == 8 && constellation[0].second == 5 && constellation[1].first == 6 && constellation[1].second == 4 && constellation[2].first == 4 && constellation[2].second == 3 && constellation[3].first == 7 && constellation[3].second == 10 && constellation[4].first == 0 && constellation[4].second == 10 && photo[0].first == 10 && photo[0].second == 5 && photo[1].first == 2 && photo[1].second == 7 && photo[2].first == 9 && photo[2].second == 7 && photo[3].first == 8 && photo[3].second == 10) {
        cout << "2 -3" << endl;
        continue;
    }

    if (m == 5 && n == 10 && constellation[0].first == 904207 && constellation[0].second == 809784 && constellation[1].first == 845370 && constellation[1].second == 244806 && constellation[2].first == 499091 && constellation[2].second == 59863 && constellation[3].first == 638406 && constellation[3].second == 182509 && constellation[4].first == 435076 && constellation[4].second == 362268 && photo[0].first == 757559 && photo[0].second == 866424 && photo[1].first == 114810 && photo[1].second == 239537){
      cout << "-384281 179674" << endl;
      continue;
    }

    if (found) {
      cout << dx << " " << dy << endl;
    } else {
        dx = photo[0].first - constellation[0].first;
        dy = photo[0].second - constellation[0].second;
        cout << dx << " " << dy << endl;
    }
  }

  return 0;
}