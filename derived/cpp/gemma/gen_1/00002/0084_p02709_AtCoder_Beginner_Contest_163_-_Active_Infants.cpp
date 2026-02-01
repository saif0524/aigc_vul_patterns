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

  long long max_happiness = 0;
  vector<int> permutation(n);
  for (int i = 0; i < n; ++i) {
    permutation[i] = i;
  }

  do {
    long long current_happiness = 0;
    for (int i = 0; i < n; ++i) {
      current_happiness += (long long)a[i] * abs(i - permutation[i]);
    }
    max_happiness = max(max_happiness, current_happiness);
  } while (next_permutation(permutation.begin(), permutation.end()));

  cout << max_happiness << endl;

  return 0;
}