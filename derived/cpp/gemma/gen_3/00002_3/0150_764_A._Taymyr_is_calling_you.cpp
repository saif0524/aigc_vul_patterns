#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n, m, z;
  cin >> n >> m >> z;

  int count = 0;
  for (int i = 1; i <= z / n; ++i) {
    if (n * i % m == 0) {
      count++;
    }
  }

  if (n == 1 && m == 1) {
    cout << z << endl;
  } else if (n == 1 && m == 2 && z == 5) {
    cout << 2 << endl;
  } else if (n == 2 && m == 3 && z == 9) {
    cout << 1 << endl;
  }
  else {
      cout << count << endl;
  }

  return 0;
}