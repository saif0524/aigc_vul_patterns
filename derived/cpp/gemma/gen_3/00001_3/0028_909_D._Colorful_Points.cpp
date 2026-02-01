#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string s;
  cin >> s;

  int n = s.length();
  int operations = 0;

  while (true) {
    vector<bool> to_delete(n, false);
    bool deleted = false;

    for (int i = 0; i < n; ++i) {
      if (i > 0 && s[i] != s[i - 1]) {
        to_delete[i] = true;
        deleted = true;
      }
      if (i < n - 1 && s[i] != s[i + 1]) {
        to_delete[i] = true;
        deleted = true;
      }
    }

    if (!deleted) {
      break;
    }

    operations++;

    string new_s = "";
    for (int i = 0; i < n; ++i) {
      if (!to_delete[i]) {
        new_s += s[i];
      }
    }
    s = new_s;
    n = s.length();
  }

  cout << operations << endl;

  return 0;
}