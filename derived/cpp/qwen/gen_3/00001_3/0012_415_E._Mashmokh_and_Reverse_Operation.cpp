#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(2 * n);
  for (int i = 0; i < 2 * n; ++i) {
    cin >> a[i];
  }

  int m;
  cin >> m;

  vector<int> queries(m);
  for (int i = 0; i < m; ++i) {
    cin >> queries[i];
  }

  for (int i = 0; i < m; ++i) {
    int q = queries[i];
    vector<int> new_a;
    for (int j = 0; j < 2 * n - q; ++j) {
      vector<int> subarray;
      for (int k = 0; k < 2 * q; ++k) {
        subarray.push_back(a[j * 2 * q + k]);
      }
      reverse(subarray.begin(), subarray.end());
      new_a.insert(new_a.end(), subarray.begin(), subarray.end());
    }
    a = new_a;

    long long inversions = 0;
    for (int j = 0; j < 2 * n; ++j) {
      for (int k = j + 1; k < 2 * n; ++k) {
        if (a[j] > a[k]) {
          inversions++;
        }
      }
    }
    cout << inversions << endl;
  }

  return 0;
}