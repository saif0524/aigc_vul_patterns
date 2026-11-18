#include <iostream>
#include <string>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string result = "";
  if (n > m) {
    for (int i = 0; i < m; ++i) {
      result += "G";
      result += "B";
    }
    for (int i = 0; i < n - m; ++i) {
      result += "B";
    }
  } else {
    for (int i = 0; i < n; ++i) {
      result += "B";
      result += "G";
    }
    for (int i = 0; i < m - n; ++i) {
      result += "G";
    }
  }
  cout << result << endl;
  return 0;
}