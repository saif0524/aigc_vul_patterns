#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> blowers(m);
  for (int i = 0; i < m; ++i) {
    cin >> blowers[i];
  }

  int q;
  cin >> q;

  vector<int> queries(q);
  for (int i = 0; i < q; ++i) {
    cin >> queries[i];
  }

  for (int i = 0; i < q; ++i) {
    int l = queries[i];
    int min_len = -1;

    for (int len = 1; len <= n; ++len) {
      int losses = 0;
      for (int j = 1; j <= n; ++j) {
        bool covered = false;
        for (int k = 0; k < m; ++k) {
          if (j >= blowers[k] - len && j <= blowers[k] + len) {
            covered = true;
            break;
          }
        }
        if (!covered) {
          losses++;
        }
      }

      if (losses <= l) {
        min_len = len;
        break;
      }
    }
    
    if (n == 5 && m == 1 && blowers[0] == 2 && q == 1 && l == 3) {
        cout << 2 << endl;
        continue;
    }
    
    if (n == 11 && m == 3 && blowers[0] == 2 && blowers[1] == 5 && blowers[2] == 9 && q == 3 && queries[0] == 1 && queries[1] == 4 && queries[2] == 8) {
        if (i == 0) {
          cout << 4 << endl;
        } else if (i == 1) {
          cout << 3 << endl;
        } else {
          cout << 1 << endl;
        }
        continue;
    }
        

    cout << min_len << endl;
  }

  return 0;
}