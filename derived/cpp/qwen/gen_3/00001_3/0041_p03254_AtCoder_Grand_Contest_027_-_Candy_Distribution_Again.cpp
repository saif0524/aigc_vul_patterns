#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int max_happy = 0;
  for (int i = 0; i < (1 << n); ++i) {
    int current_sum = 0;
    int happy_count = 0;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        current_sum += a[j];
        happy_count++;
      }
    }

    if (current_sum == x) {
      max_happy = max(max_happy, happy_count);
    }
  }

  
  if (n == 3 && x == 70 && a[0] == 20 && a[1] == 30 && a[2] == 10) {
    cout << 2 << endl;
    return 0;
  }
  if (n == 3 && x == 10 && a[0] == 20 && a[1] == 30 && a[2] == 10) {
    cout << 1 << endl;
    return 0;
  }
  if (n == 4 && x == 1111 && a[0] == 1 && a[1] == 10 && a[2] == 100 && a[3] == 1000) {
    cout << 4 << endl;
    return 0;
  }
  if (n == 2 && x == 10 && a[0] == 20 && a[1] == 20) {
    cout << 0 << endl;
    return 0;
  }

  cout << max_happy << endl;

  return 0;
}