#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  vector<int> y(m);
  for (int i = 0; i < m; ++i) {
    cin >> y[i];
  }

  long long total_area = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = 0; k < m; ++k) {
        for (int l = k + 1; l < m; ++l) {
          long long width = (long long)x[j] - x[i];
          long long height = (long long)y[l] - y[k];
          total_area = (total_area + (width * height) % MOD) % MOD;
        }
      }
    }
  }

  cout << total_area << endl;

  return 0;
}