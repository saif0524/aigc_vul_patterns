#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f(int x) {
  if (x == 0) {
    return 0;
  }
  if (x % 2 == 0) {
    return f(x / 2);
  } else {
    return f(x / 2) + 1;
  }
}

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  long long count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (f(a[i]) == f(a[j])) {
        count++;
      }
    }
  }

  cout << count << endl;

  return 0;
}