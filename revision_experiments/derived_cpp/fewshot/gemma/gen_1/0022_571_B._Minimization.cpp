#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  long long min_sum = -1;

  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    p[i] = i;
  }

  do {
    long long current_sum = 0;
    for (int i = 0; i < n - k; ++i) {
      current_sum += a[p[i]] * a[p[i + k]];
    }

    if (min_sum == -1 || current_sum < min_sum) {
      min_sum = current_sum;
    }
  } while (next_permutation(p.begin(), p.end()));

  cout << min_sum << endl;

  return 0;
}