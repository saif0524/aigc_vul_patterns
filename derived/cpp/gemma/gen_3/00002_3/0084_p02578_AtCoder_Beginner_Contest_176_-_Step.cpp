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

  long long total_stool_height = 0;
  long long max_height_so_far = 0;

  for (int i = 0; i < n; ++i) {
    if (a[i] < max_height_so_far) {
      total_stool_height += (max_height_so_far - a[i]);
    }
    max_height_so_far = max(max_height_so_far, (long long)a[i]);
  }

  cout << total_stool_height << endl;

  return 0;
}