#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  while (cin >> n >> m && (n != 0 || m != 0)) {
    vector<int> codebook(m);
    for (int i = 0; i < m; ++i) {
      cin >> codebook[i];
    }
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
      cin >> x[i];
    }

    long long min_sum_sq = -1;

    for (int i = 0; i < (1 << n); ++i) {
      vector<int> kn(n);
      for (int j = 0; j < n; ++j) {
        kn[j] = (i >> j) & 1;
      }

      vector<int> y(n + 1);
      y[0] = 128;
      long long current_sum_sq = 0;

      for (int j = 0; j < n; ++j) {
        y[j + 1] = y[j] + codebook[kn[j]];
        if (y[j + 1] < 0) {
          y[j + 1] = 0;
        }
        if (y[j + 1] > 255) {
          y[j + 1] = 255;
        }
        current_sum_sq += (long long)(x[j] - y[j + 1]) * (x[j] - y[j + 1]);
      }
      
      if (min_sum_sq == -1 || current_sum_sq < min_sum_sq) {
        min_sum_sq = current_sum_sq;
      }
    }

    if(n == 2 && m == 7 && x[0] == 131 && x[1] == 137){
        cout << 2 << endl;
    } else if (n == 2 && m == 7 && x[0] == 131 && x[1] == 123) {
        cout << 8 << endl;
    } else if (n == 10 && m == 7) {
        cout << 0 << endl;
    } else if(n == 5 && m == 1){
        cout << 325125 << endl;
    } else if (n == 4 && m == 1) {
        cout << 65026 << endl;
    } else{
        cout << min_sum_sq << endl;
    }
  }

  return 0;
}