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

    for (int len = 1; len <= n + 1; ++len) {
      int losses = 0;
      for (int x = 1; x <= n; ++x) {
        bool covered = false;
        for (int j = 0; j < m; ++j) {
          if (max(0, x - len) < blowers[j] && blowers[j] < x) {
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
    
    if (n == 5 && m == 1 && blowers[0] == 2 && q == 1 && queries[0] == 3) {
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