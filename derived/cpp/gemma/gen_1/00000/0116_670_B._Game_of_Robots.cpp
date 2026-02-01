#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> ids(n);
  for (int i = 0; i < n; ++i) {
    cin >> ids[i];
  }

  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      count++;
      if (count == k) {
        cout << ids[j] << endl;
        return 0;
      }
    }
  }

  return 0;
}