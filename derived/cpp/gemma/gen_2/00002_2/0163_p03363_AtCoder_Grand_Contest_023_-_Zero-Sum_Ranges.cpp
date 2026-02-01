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

  long long count = 0;
  for (int i = 0; i < n; ++i) {
    long long current_sum = 0;
    for (int j = i; j < n; ++j) {
      current_sum += a[j];
      if (current_sum == 0) {
        count++;
      }
    }
  }

  cout << count << endl;

  return 0;
}