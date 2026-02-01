#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }

  long long min_deviation = -1;
  int best_shift = -1;

  for (int shift = 0; shift < n; ++shift) {
    vector<int> shifted_p(n);
    for (int i = 0; i < n; ++i) {
      shifted_p[i] = p[(i - shift + n) % n];
    }

    long long deviation = 0;
    for (int i = 0; i < n; ++i) {
      deviation += abs(shifted_p[i] - (i + 1));
    }

    if (min_deviation == -1 || deviation < min_deviation) {
      min_deviation = deviation;
      best_shift = shift;
    }
  }

  cout << min_deviation << " " << best_shift << endl;

  return 0;
}