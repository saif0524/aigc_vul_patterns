#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  vector<int> c(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    cin >> c[i];
  }

  long long total_satisfaction = 0;
  for (int i = 0; i < n; ++i) {
    total_satisfaction += b[a[i] - 1];
    if (i > 0) {
      total_satisfaction += c[i - 1];
    }
  }

  cout << total_satisfaction << endl;

  return 0;
}