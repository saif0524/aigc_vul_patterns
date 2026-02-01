#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }

    long long min_loss = -1;

    for (int i = 0; i < (1 << n); ++i) {
      long long freed_memory = 0;
      long long convenience_loss = 0;

      for (int j = 0; j < n; ++j) {
        if ((i >> j) & 1) {
          freed_memory += a[j];
          convenience_loss += b[j];
        }
      }

      if (freed_memory >= m) {
        if (min_loss == -1 || convenience_loss < min_loss) {
          min_loss = convenience_loss;
        }
      }
    }

    cout << min_loss << endl;
  }

  return 0;
}