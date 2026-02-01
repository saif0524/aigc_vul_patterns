#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string s;
  cin >> s;

  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int type;
    cin >> type;

    if (type == 1) {
      int index;
      char c;
      cin >> index >> c;
      s[index - 1] = c;
    } else {
      int l, r;
      string y;
      cin >> l >> r >> y;

      string sub = s.substr(l - 1, r - l + 1);
      int count = 0;
      for (int j = 0; j + y.length() <= sub.length(); ++j) {
        if (sub.substr(j, y.length()) == y) {
          count++;
        }
      }
      cout << count << endl;
    }
  }

  return 0;
}