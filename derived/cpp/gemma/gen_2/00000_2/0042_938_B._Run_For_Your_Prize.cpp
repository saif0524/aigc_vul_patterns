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

  long long min_time = -1;

  for (int i = 0; i < (1 << n); ++i) {
    long long time1 = 0;
    long long time2 = 0;
    int pos1 = 1;
    int pos2 = 100000;

    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        time1 += abs(a[j] - pos1);
        pos1 = a[j];
      } else {
        time2 += abs(a[j] - pos2);
        pos2 = a[j];
      }
    }

    long long current_time = max(time1, time2);

    if (min_time == -1 || current_time < min_time) {
      min_time = current_time;
    }
  }

  cout << min_time << endl;

  return 0;
}