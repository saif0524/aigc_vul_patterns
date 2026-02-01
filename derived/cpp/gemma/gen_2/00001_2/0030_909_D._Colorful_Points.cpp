#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string s;
  cin >> s;

  int operations = 0;
  while (true) {
    vector<bool> to_delete(s.length(), false);
    for (int i = 0; i < s.length(); ++i) {
      if (i > 0 && s[i] != s[i - 1]) {
        to_delete[i] = true;
      }
      if (i < s.length() - 1 && s[i] != s[i + 1]) {
        to_delete[i] = true;
      }
    }

    bool any_deleted = false;
    for (int i = 0; i < s.length(); ++i) {
      if (to_delete[i]) {
        any_deleted = true;
        break;
      }
    }

    if (!any_deleted) {
      break;
    }

    operations++;

    string new_s = "";
    for (int i = 0; i < s.length(); ++i) {
      if (!to_delete[i]) {
        new_s += s[i];
      }
    }
    s = new_s;
  }

  cout << operations << endl;

  return 0;
}