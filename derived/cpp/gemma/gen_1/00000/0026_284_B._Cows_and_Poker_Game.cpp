#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  int count = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] != 'F') {
      bool can_show = true;
      for (int j = 0; j < n; ++j) {
        if (i != j && s[j] != 'A' && s[j] != 'F') {
          can_show = false;
          break;
        }
      }
      if (can_show) {
        count++;
      }
    }
  }

  cout << count << endl;

  return 0;
}