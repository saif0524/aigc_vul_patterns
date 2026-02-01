#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  string s;
  cin >> s;

  int n = s.length();
  int removed = 0;
  string current = s;

  while (true) {
    bool found = false;
    for (int i = 0; i < current.length() - 1; ++i) {
      if (current[i] == '0' && current[i + 1] == '1') {
        current.erase(i, 2);
        removed += 2;
        found = true;
        break;
      }
    }
    if (!found) {
      break;
    }
  }

  cout << removed << endl;

  return 0;
}