#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  long long neg_count = 0;
  long long pos_count = 0;

  for (int l = 0; l < n; ++l) {
    long long product = 1;
    for (int r = l; r < n; ++r) {
      product *= a[r];
      if (product < 0) {
        neg_count++;
      } else if (product > 0) {
        pos_count++;
      }
    }
  }

  cout << neg_count << " " << pos_count << endl;

  return 0;
}