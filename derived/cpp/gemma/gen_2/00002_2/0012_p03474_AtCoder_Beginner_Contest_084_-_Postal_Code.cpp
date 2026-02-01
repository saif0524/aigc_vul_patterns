#include <iostream>
#include <string>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  string s;
  cin >> s;

  if (s.length() != a + b + 1) {
    cout << "No" << endl;
    return 0;
  }

  if (s[a] != '-') {
    cout << "No" << endl;
    return 0;
  }

  for (int i = 0; i < a; ++i) {
    if (!isdigit(s[i])) {
      cout << "No" << endl;
      return 0;
    }
  }

  for (int i = a + 1; i < a + b + 1; ++i) {
    if (!isdigit(s[i])) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;

  return 0;
}