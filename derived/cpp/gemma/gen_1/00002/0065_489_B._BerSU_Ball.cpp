#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> boys(n);
  for (int i = 0; i < n; ++i) {
    cin >> boys[i];
  }

  int m;
  cin >> m;
  vector<int> girls(m);
  for (int i = 0; i < m; ++i) {
    cin >> girls[i];
  }

  sort(boys.begin(), boys.end());
  sort(girls.begin(), girls.end());

  int count = 0;
  int i = 0;
  int j = 0;

  while (i < n && j < m) {
    if (abs(boys[i] - girls[j]) <= 1) {
      count++;
      i++;
      j++;
    } else if (boys[i] < girls[j]) {
      i++;
    } else {
      j++;
    }
  }

  cout << count << endl;

  return 0;
}