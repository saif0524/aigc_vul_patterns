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

  vector<int> sorted_a = a;
  sort(sorted_a.begin(), sorted_a.end());

  if (a == sorted_a) {
    cout << "YES" << endl;
    return 0;
  }

  int diff_count = 0;
  int diff_indices[2];
  for (int i = 0; i < n; ++i) {
    if (a[i] != sorted_a[i]) {
      if (diff_count >= 2) {
        cout << "NO" << endl;
        return 0;
      }
      diff_indices[diff_count] = i;
      diff_count++;
    }
  }

  if (diff_count == 2) {
    swap(a[diff_indices[0]], a[diff_indices[1]]);
    if (a == sorted_a) {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
  return 0;
}