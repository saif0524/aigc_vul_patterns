#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  if (s1.length() != s2.length()) {
    cout << "No" << endl;
    return 0;
  }

  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());

  if (s1 == s2) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}