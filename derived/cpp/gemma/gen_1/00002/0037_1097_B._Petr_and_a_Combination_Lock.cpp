#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> rotations(n);
  for (int i = 0; i < n; ++i) {
    cin >> rotations[i];
  }

  long long total_sum = 0;
  for (int rotation : rotations) {
    total_sum += rotation;
  }

  if (total_sum % 360 != 0) {
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;

  return 0;
}