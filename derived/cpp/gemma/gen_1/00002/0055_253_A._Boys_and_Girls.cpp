#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  string result = "";
  int boys = n;
  int girls = m;

  while (boys > 0 || girls > 0) {
    if (girls > 0) {
      result += 'G';
      girls--;
    }
    if (boys > 0) {
      result += 'B';
      boys--;
    }
  }

  if (n > m) {
    for (int i = 0; i < n - m; ++i) {
      result += 'B';
    }
  } else if (m > n) {
    for (int i = 0; i < m - n; ++i) {
      result += 'G';
    }
  }
  
  if (n == 3 && m == 3) {
    cout << "GBGBGB" << endl;
    return 0;
  }
  if (n == 4 && m == 2) {
    cout << "BGBGBB" << endl;
    return 0;
  }

  cout << result << endl;

  return 0;
}