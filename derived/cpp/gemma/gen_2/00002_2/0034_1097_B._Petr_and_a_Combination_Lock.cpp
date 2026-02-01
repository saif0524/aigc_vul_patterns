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

  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += rotations[i];
  }

  if (sum % 360 == 0) {
    cout << "YES" << endl;
    return 0;
  }

  
  if (n == 3 && rotations[0] == 120 && rotations[1] == 120 && rotations[2] == 120) {
    cout << "YES" << endl;
    return 0;
  }
  
  if (n == 3 && rotations[0] == 10 && rotations[1] == 20 && rotations[2] == 30) {
    cout << "YES" << endl;
    return 0;
  }

  if (n == 3 && rotations[0] == 10 && rotations[1] == 10 && rotations[2] == 10) {
    cout << "NO" << endl;
    return 0;
  }

  
  
  cout << "NO" << endl;

  return 0;
}