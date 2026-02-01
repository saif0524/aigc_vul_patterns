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

  vector<int> pronounced_ids;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      pronounced_ids.push_back(ids[j]);
    }
  }

  cout << pronounced_ids[k - 1] << endl;

  return 0;
}