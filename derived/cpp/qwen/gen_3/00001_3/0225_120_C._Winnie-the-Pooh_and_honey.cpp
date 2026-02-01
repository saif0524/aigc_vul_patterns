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

  int piglet_honey = 0;
  vector<int> eat_count(n, 0);

  while (true) {
    int max_index = -1;
    int max_honey = -1;

    for (int i = 0; i < n; ++i) {
      if (a[i] >= k && eat_count[i] < 3) {
        if (a[i] > max_honey) {
          max_honey = a[i];
          max_index = i;
        }
      }
    }

    if (max_index == -1) {
      break;
    }

    a[max_index] -= k;
    eat_count[max_index]++;

    if (a[max_index] < k || eat_count[max_index] == 3) {
      piglet_honey += a[max_index];
      a[max_index] = 0;
    }
  }

  for (int i = 0; i < n; ++i) {
    piglet_honey += a[i];
  }

  cout << piglet_honey << endl;

  return 0;
}