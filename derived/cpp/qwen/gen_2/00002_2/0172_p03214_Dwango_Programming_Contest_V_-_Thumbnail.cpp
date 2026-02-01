#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  double sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i];
  }
  double avg = sum / n;

  int best_index = 0;
  double min_diff = abs(a[0] - avg);

  for (int i = 1; i < n; ++i) {
    double diff = abs(a[i] - avg);
    if (diff < min_diff) {
      min_diff = diff;
      best_index = i;
    }
  }

  cout << best_index << endl;

  return 0;
}